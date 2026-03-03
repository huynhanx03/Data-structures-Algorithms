import httpx
import json
import time
from typing import List, Dict, Any

from CodeCommit.config.config import Config
from CodeCommit.pydomain.submission import Submission

LEETCODE_GRAPHQL = "https://leetcode.com/graphql"

SUBMISSION_LIST_QUERY = """query submissionList($offset: Int!, $limit: Int!, $questionSlug: String!) {
  submissionList(offset: $offset, limit: $limit, questionSlug: $questionSlug) {
    hasNext
    submissions {
      id
      title
      titleSlug
      statusDisplay
      lang
      timestamp
    }
  }
}"""

SUBMISSION_DETAILS_QUERY = """query submissionDetails($submissionId: Int!) {
  submissionDetails(submissionId: $submissionId) {
    code
    timestamp
    statusCode
    user {
      username
    }
    lang {
      name
      verboseName
    }
    question {
      questionId
      titleSlug
      title
      difficulty
      topicTags {
        name
      }
    }
    runtimeDisplay
    memoryDisplay
    runtimePercentile
    memoryPercentile
  }
}"""

QUESTION_CONTENT_QUERY = """query questionContent($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    content
  }
}"""

class LeetCode:
    def __init__(self, cfg: Config):
        self.session_token = cfg.leetcode_session
        self.csrf_token = cfg.leetcode_csrf
        
        self.client = httpx.Client()
        self.client.cookies.set("LEETCODE_SESSION", self.session_token, domain="leetcode.com")
        self.client.cookies.set("csrftoken", self.csrf_token, domain="leetcode.com")
        
        self.client.headers.update({
            "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko)",
            "Content-Type": "application/json",
            "Referer": "https://leetcode.com",
            "X-CSRFToken": self.csrf_token
        })

    def _do_graphql(self, payload: Dict[str, Any]) -> Dict[str, Any]:
        resp = self.client.post(LEETCODE_GRAPHQL, json=payload, timeout=15.0)
        resp.raise_for_status()
        return resp.json()

    def fetch_submissions(self, cutoff_timestamp: int = 0) -> List[Submission]:
        # Get username first
        me_query = {"query": "{ userStatus { username } }"}
        me_res = self._do_graphql(me_query)
        username = me_res.get("data", {}).get("userStatus", {}).get("username")
        if not username:
            raise Exception("LeetCode failed to get username, maybe invalid session")

        # Fetch ACs with pagination
        results = []
        offset = 0
        limit = 20
        has_next = True
        
        while has_next:
            list_query = {
                "query": SUBMISSION_LIST_QUERY,
                "variables": {"offset": offset, "limit": limit, "questionSlug": ""}
            }
            list_res = self._do_graphql(list_query)
            sub_data = list_res.get("data", {}).get("submissionList", {})
            has_next = sub_data.get("hasNext", False)
            submissions = sub_data.get("submissions", [])
            
            if not submissions:
                break
                
            for ac in submissions:
                ts = int(ac.get("timestamp", "0"))
                if ts < cutoff_timestamp:
                    has_next = False # Stop outer loop
                    break
                    
                if ac.get("statusDisplay") != "Accepted":
                    continue
                    
                sub_id = ac.get("id")
                detail_query = {
                    "query": SUBMISSION_DETAILS_QUERY,
                    "variables": {"submissionId": int(sub_id)}
                }
            
                try:
                    detail_res = self._do_graphql(detail_query)
                    details = detail_res.get("data", {}).get("submissionDetails", {})
                    
                    question = details.get("question", {})
                    lang = details.get("lang", {})
                    tags = [t.get("name") for t in question.get("topicTags", [])]
                    
                    readme = self.fetch_readme(ac.get("titleSlug", ""))
                    
                    s = Submission(
                        platform="LeetCode",
                        id=question.get("questionId", ""),
                        title=question.get("title", ""),
                        slug=question.get("titleSlug", ""),
                        difficulty=question.get("difficulty", ""),
                        rating=0,
                        tags=tags,
                        language=lang.get("name", ""),
                        code=details.get("code", ""),
                        time_beats=details.get("runtimePercentile", 0.0),
                        memory_beats=details.get("memoryPercentile", 0.0),
                        time_display=details.get("runtimeDisplay", ""),
                        memory_display=details.get("memoryDisplay", ""),
                        link=f"https://leetcode.com/problems/{ac.get('titleSlug')}",
                        readme=readme,
                        timestamp=ts
                    )
                    
                    leethub_readme = (
                        f"<h2><a href=\"{s.link}\">{s.id}. {s.title}</a></h2>"
                        f"<h3>{s.difficulty}</h3><hr>"
                        f"{readme}"
                    )
                    s.readme = leethub_readme
                    
                    results.append(s)
                    print(f"Added: {s.id}. {s.title} ({s.language})")
                    time.sleep(1) # Rate limit protection
                    
                except Exception as e:
                    print(f"Error fetching detail for LC submission {sub_id}: {e}")
                    
            offset += limit

        return results

    def fetch_readme(self, slug: str) -> str:
        q = {
            "query": QUESTION_CONTENT_QUERY,
            "variables": {"titleSlug": slug}
        }
        try:
            res = self._do_graphql(q)
            html = res.get("data", {}).get("question", {}).get("content", "")
            if not html:
                return "No description available."
                
            import re
            s = html
            # LeetHub style keeps most HTML tags intact instead of stripping them, 
            # to render properly in GitHub Markdown as formatted text.
            s = s.replace('&nbsp;', ' ')
            # We don't strip tags because GitHub natively renders safe HTML like <ul>, <li>, <p>, <pre> brilliantly.
            
            return s.strip()
        except:
            return ""

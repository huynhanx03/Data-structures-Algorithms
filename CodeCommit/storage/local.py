import os
import json
import re
from typing import List
from CodeCommit.config.config import Config
from CodeCommit.pydomain.submission import Submission

def slugify(text: str) -> str:
    text = text.lower()
    text = re.sub(r'[^a-z0-9]+', '-', text)
    return text.strip('-')

class LocalStorage:
    def __init__(self, cfg: Config):
        self.cfg = cfg

    def get_dir_path(self, sub: Submission) -> str:
        if sub.platform == "LeetCode":
            return os.path.join(self.cfg.leetcode_dir, sub.difficulty, f"{sub.id.zfill(4)}-{sub.slug}")
        elif sub.platform == "Codeforces":
            parent = f"{sub.contest_id:04d}{sub.index}-{slugify(sub.title)}"
            return os.path.join(self.cfg.codeforces_dir, parent)
        return ""

    def save(self, sub: Submission) -> dict:
        dir_path = self.get_dir_path(sub)
        if not dir_path:
            return None

        os.makedirs(dir_path, exist_ok=True)

        if sub.platform == "LeetCode":
            file_name = f"{sub.id.zfill(4)}-{sub.slug}.{sub.ext()}"
        elif sub.platform == "Codeforces":
            file_name = f"{sub.contest_id:04d}{sub.index}-{slugify(sub.title)}.{sub.ext()}"
        else:
            return False

        # Build comment header
        ext = sub.ext().lower()
        if ext in ['py', 'rb']:
            comment_fmt = '"""\n{0}\n"""\n'
        elif ext in ['sh', 'bash']:
            comment_fmt = '# {0}\n'
            # Need to format each line with #
        elif ext in ['sql']:
            comment_fmt = '/*\n{0}\n*/\n'
        else:
            comment_fmt = '/*\n{0}\n*/\n'

        tags_str = ", ".join(sub.tags) if sub.tags else "None"
        info = (
            f" Problem: {sub.id}. {sub.title}\n"
            f" Language: {sub.language}\n"
            f" Runtime: {sub.time_display} ({sub.time_beats:.2f}%)\n"
            f" Memory: {sub.memory_display} ({sub.memory_beats:.2f}%)\n"
            f" Tags: {tags_str}"
        )
        
        if ext in ['sh', 'bash']:
            header = "\n".join([f"# {line}" for line in info.split('\n')]) + "\n"
        else:
            header = comment_fmt.format(info)

        code_path = os.path.join(dir_path, file_name)
        with open(code_path, "w", encoding="utf-8") as f:
            f.write(header + sub.code)

        result = {"code_path": code_path}

        if sub.readme:
            readme_path = os.path.join(dir_path, "README.md")
            if not os.path.exists(readme_path):
                with open(readme_path, "w", encoding="utf-8") as f:
                    f.write(sub.readme)
                result["readme_path"] = readme_path

        return result

    def get_database_path(self, platform: str) -> str:
        if platform == "LeetCode":
            return os.path.join(self.cfg.leetcode_dir, "data.json")
        elif platform == "Codeforces":
            return os.path.join(self.cfg.codeforces_dir, "data.json")
        return ""

    def load_submissions(self, platform: str) -> List[Submission]:
        db_path = self.get_database_path(platform)
        if not os.path.exists(db_path):
            return []

        with open(db_path, "r", encoding="utf-8") as f:
            data = json.load(f)

        res = []
        for item in data:
            s = Submission(
                platform=item.get("Platform", platform),
                id=item.get("ID", ""),
                title=item.get("Title", ""),
                slug=item.get("Slug", ""),
                difficulty=item.get("Difficulty", ""),
                rating=item.get("Rating", 0),
                tags=item.get("Tags", []),
                language=item.get("Language", ""),
                time_beats=item.get("TimeBeats", 0.0),
                memory_beats=item.get("MemoryBeats", 0.0),
                time_display=item.get("TimeDisplay", ""),
                memory_display=item.get("MemoryDisplay", ""),
                link=item.get("Link", ""),
                contest_id=item.get("ContestID", 0),
                index=item.get("Index", ""),
                timestamp=item.get("Timestamp", 0)
            )
            res.append(s)
        return res

    def save_database(self, platform: str, subs: List[Submission]) -> bool:
        db_path = self.get_database_path(platform)
        os.makedirs(os.path.dirname(db_path), exist_ok=True)

        data = []
        for s in subs:
            item = {
                "Platform": s.platform,
                "ID": s.id,
                "Title": s.title,
                "Slug": s.slug,
                "Difficulty": s.difficulty,
                "Rating": s.rating,
                "Tags": s.tags,
                "Language": s.language,
                "TimeBeats": s.time_beats,
                "MemoryBeats": s.memory_beats,
                "TimeDisplay": s.time_display,
                "MemoryDisplay": s.memory_display,
                "Link": s.link,
                "ContestID": s.contest_id,
                "Index": s.index,
                "Timestamp": s.timestamp
            }
            data.append(item)

        with open(db_path, "w", encoding="utf-8") as f:
            json.dump(data, f, ensure_ascii=False, indent=2)

        return True

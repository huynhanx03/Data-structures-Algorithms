import os
from typing import List, Dict
from CodeCommit.config.config import Config
from CodeCommit.pydomain.submission import Submission

class MasterReadme:
    def __init__(self, cfg: Config):
        self.cfg = cfg

    def generate(self, subs: List[Submission], platform: str, out_path: str):
        if not subs:
            return
            
        topics: Dict[str, List[Submission]] = {}
        seen = set()
        for s in subs:
            if not s.tags:
                if ("Uncategorized", s.id) not in seen:
                    topics.setdefault("Uncategorized", []).append(s)
                    seen.add(("Uncategorized", s.id))
                continue
            for t in s.tags:
                if (t, s.id) not in seen:
                    topics.setdefault(t, []).append(s)
                    seen.add((t, s.id))
                
        # Sort topics alphabetically
        sorted_topics = sorted(topics.keys())
        
        lines = []
        if platform == "LeetCode":
            lines.append(f"# LEETCODE\n")
            for t in sorted_topics:
                lines.append(f"## {t}")
                lines.append("| # | Title | Difficulty |")
                lines.append("| :--- | :--- | :---: |")
                
                # Sort submissions by ID
                t_subs = sorted(topics[t], key=lambda x: int(x.id) if x.id.isdigit() else 9999)
                for s in t_subs:
                    local_link = f"./{self.cfg.leetcode_dir}/{s.difficulty}/{s.id.zfill(4)}-{s.slug}"
                    lines.append(f"| {s.id} | [{s.title}]({local_link}) | {s.difficulty} |")
                lines.append("")
                lines.append("---\n")
                
        elif platform == "Codeforces":
            lines.append(f"# 🟦 C O D E F O R C E S\n")
            for t in sorted_topics:
                lines.append(f"## {t}")
                lines.append("| ID | Title | Rating | Link |")
                lines.append("| :--- | :--- | :---: | :---: |")
                
                # Sort submissions by contest ID
                t_subs = sorted(topics[t], key=lambda x: x.contest_id)
                for s in t_subs:
                    from CodeCommit.storage.local import slugify
                    parent = f"{s.contest_id:04d}{s.index}-{slugify(s.title)}"
                    local_link = f"./{self.cfg.codeforces_dir}/{parent}"
                    lines.append(f"| {s.contest_id}{s.index} | [{s.title}]({local_link}) | {s.rating} | [Link]({s.link}) |")
                lines.append("")
                lines.append("---\n")

        os.makedirs(os.path.dirname(out_path), exist_ok=True)
        with open(out_path, "w", encoding="utf-8") as f:
            f.write("\n".join(lines))

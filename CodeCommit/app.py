import os
import datetime
from typing import List
import httpx
from CodeCommit.config.config import Config
from CodeCommit.pydomain.submission import Submission
from CodeCommit.storage.local import LocalStorage
from CodeCommit.generator.readme import MasterReadme
from CodeCommit.provider.leetcode import LeetCode

class App:
    def __init__(self, cfg: Config):
        self.cfg = cfg
        self.store = LocalStorage(cfg)
        self.generator = MasterReadme(cfg)

    def run(self):
        print("🚀 Starting CodeCommit Sync...")
        self.sync_leetcode()
        print("✅ Done.")

    def sync_leetcode(self):
        print("Fetching LeetCode...")
        try:
            lc = LeetCode(self.cfg)
            
            cutoff = self._get_cutoff()
            new_subs = lc.fetch_submissions(cutoff)
            
            existing = self.store.load_submissions("LeetCode")
            seen = {f"{s.id}-{s.ext()}": True for s in existing}
            
            appended = False
            for sub in new_subs:
                key = f"{sub.id}-{sub.ext()}"
                if key in seen:
                    continue
                    
                saved_paths = self.store.save(sub)
                if saved_paths:
                    existing.append(sub)
                    self._append_commit_script(sub, saved_paths)
                    appended = True
                    print(f"LC Added: {sub.id}. {sub.title} ({sub.ext()})")
                    
            if appended:
                existing.sort(key=lambda x: x.timestamp)
                self.store.save_database("LeetCode", existing)
                self.generator.generate(existing, "LeetCode", os.path.join(self.cfg.leetcode_dir, "README.md"))
                self.notify_discord(len(new_subs))
                
        except Exception as e:
            print(f"LC Sync Error: {e}")

    def _get_cutoff(self) -> int:
        if self.cfg.sync_since:
            import dateparser
            dt = dateparser.parse(self.cfg.sync_since)
            if dt:
                return int(dt.timestamp())
        # Default to midnight today if not specified
        now = datetime.datetime.now()
        midnight = now.replace(hour=0, minute=0, second=0, microsecond=0)
        return int(midnight.timestamp())

    def _append_commit_script(self, sub: Submission, saved_paths: dict):
        script_file = "commits.sh"
        
        with open(script_file, "a", encoding="utf-8") as f:
            if "readme_path" in saved_paths:
                f.write(f"git add \"{saved_paths['readme_path']}\" || true\n")
                f.write(f"git commit -m \"Create README - {sub.title}\" || true\n")
            
            if "code_path" in saved_paths:
                code_msg = ""
                if sub.platform == "LeetCode":
                    if sub.time_display:
                        code_msg = f"Time: {sub.time_display} ({sub.time_beats:.2f}%), Space: {sub.memory_display} ({sub.memory_beats:.2f}%) - {sub.title}"
                    else:
                        code_msg = f"{sub.id}. {sub.title} ({sub.difficulty})"
                
                f.write(f"git add \"{saved_paths['code_path']}\" || true\n")
                f.write(f"git commit -m \"{code_msg}\" || true\n")

    def notify_discord(self, added_count: int):
        webhook_url = self.cfg.discord_webhook
        if not webhook_url or added_count == 0:
            return
            
        payload = {
            "embeds": [{
                "title": "✅ CodePusher Sync Successful",
                "description": f"Successfully pulled **{added_count}** new LeetCode submissions!\nView your repository [here](https://github.com/huynhanx03/Data-structures-Algorithms).",
                "color": 3066993, # Green
                "timestamp": datetime.datetime.utcnow().isoformat() + "Z"
            }]
        }
        
        try:
            httpx.post(webhook_url, json=payload, timeout=10.0)
        except Exception as e:
            print(f"Discord Webhook Error: {e}")

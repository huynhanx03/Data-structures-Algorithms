import os
import sys

class Config:
    def __init__(self):
        self.leetcode_session = os.environ.get("LEETCODE_SESSION", "")
        self.leetcode_csrf = os.environ.get("LEETCODE_CSRF", "")
        
        self.leetcode_dir = os.environ.get("LEETCODE_DIR", "leetcode")
        self.sync_platform = os.environ.get("SYNC_PLATFORM", "leetcode")
        self.sync_since = os.environ.get("SYNC_SINCE", "")
        self.discord_webhook = os.environ.get("DISCORD_WEBHOOK", "")

def load_config() -> Config:
    cfg = Config()
    
    if not cfg.leetcode_session or not cfg.leetcode_csrf:
        print("❌ Missing LEETCODE credentials in environment", file=sys.stderr)
        sys.exit(1)
            
    return cfg

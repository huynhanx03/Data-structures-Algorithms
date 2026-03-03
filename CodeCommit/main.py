import sys
from CodeCommit.config.config import load_config
from CodeCommit.app import App

def main():
    cfg = load_config()
    app = App(cfg)
    app.run()

if __name__ == "__main__":
    main()

from dataclasses import dataclass, field
from typing import List, Optional

@dataclass
class Submission:
    platform: str
    id: str
    title: str
    slug: str
    difficulty: str
    rating: int
    tags: List[str]
    language: str
    
    code: str = field(repr=False, default="")
    time_beats: float = 0.0
    memory_beats: float = 0.0
    time_display: str = ""
    memory_display: str = ""
    
    link: str = ""
    readme: str = field(repr=False, default="")
    
    contest_id: int = 0
    index: str = ""
    timestamp: int = 0

    def ext(self) -> str:
        l = self.language.lower()
        if "cpp" in l or "c++" in l or "gcc" in l:
            return "cpp"
        if "go" in l:
            return "go"
        if "py" in l:
            return "py"
        if "java" in l:
            return "java"
        if "js" in l or "javascript" in l:
            return "js"
        if "ts" in l or "typescript" in l:
            return "ts"
        if "rs" in l or "rust" in l:
            return "rs"
        if "c#" in l or "csharp" in l:
            return "cs"
        return "txt"

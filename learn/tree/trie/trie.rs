use std::collections::HashMap;

#[derive(Default)]
pub struct TrieNode {
    pub children: HashMap<char, TrieNode>,
    pub is_end: bool,
}

#[derive(Default)]
pub struct Trie {
    pub root: TrieNode,
}

impl Trie {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn insert(&mut self, word: &str) {
        let mut curr = &mut self.root;
        for ch in word.chars() {
            curr = curr.children.entry(ch).or_default();
        }
        curr.is_end = true;
    }

    pub fn search(&self, word: &str) -> bool {
        let mut curr = &self.root;
        for ch in word.chars() {
            if let Some(node) = curr.children.get(&ch) {
                curr = node;
            } else {
                return false;
            }
        }
        curr.is_end
    }

    pub fn starts_with(&self, prefix: &str) -> bool {
        let mut curr = &self.root;
        for ch in prefix.chars() {
            if let Some(node) = curr.children.get(&ch) {
                curr = node;
            } else {
                return false;
            }
        }
        true
    }
}

pub struct HashNode {
    pub key: i32,
    pub value: i32,
    pub next: Option<Box<HashNode>>,
}

pub struct HashTableChaining {
    capacity: usize,
    table: Vec<Option<Box<HashNode>>>,
}

impl HashTableChaining {
    pub fn new(size: usize) -> Self {
        let mut table = Vec::with_capacity(size);
        for _ in 0..size {
            table.push(None);
        }
        HashTableChaining {
            capacity: size,
            table,
        }
    }

    fn hash_function(&self, key: i32) -> usize {
        key.rem_euclid(self.capacity as i32) as usize
    }

    pub fn insert(&mut self, key: i32, value: i32) {
        let index = self.hash_function(key);
        let mut curr = &mut self.table[index];

        loop {
            match curr {
                Some(node) if node.key == key => {
                    node.value = value;
                    return;
                }
                Some(node) => {
                    curr = &mut node.next;
                }
                None => {
                    *curr = Some(Box::new(HashNode {
                        key,
                        value,
                        next: None,
                    }));
                    return;
                }
            }
        }
    }

    pub fn search(&self, key: i32) -> Option<i32> {
        let index = self.hash_function(key);
        let mut curr = &self.table[index];

        while let Some(node) = curr {
            if node.key == key {
                return Some(node.value);
            }
            curr = &node.next;
        }
        None
    }

    pub fn remove(&mut self, key: i32) {
        let index = self.hash_function(key);
        let mut curr = &mut self.table[index];

        loop {
            match curr {
                Some(node) if node.key == key => {
                    *curr = node.next.take();
                    return;
                }
                Some(node) => {
                    curr = &mut node.next;
                }
                None => return,
            }
        }
    }
}

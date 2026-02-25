#[derive(Clone)]
pub struct DoubleHashItem {
    pub key: i32,
    pub value: i32,
    pub deleted: bool,
}

pub struct DoubleHashing {
    capacity: usize,
    size: usize,
    table: Vec<Option<DoubleHashItem>>,
    prime: usize,
}

impl DoubleHashing {
    pub fn new(capacity: usize, prime: usize) -> Self {
        DoubleHashing {
            capacity,
            size: 0,
            table: vec![None; capacity],
            prime,
        }
    }

    fn hash1(&self, key: i32) -> usize {
        key.rem_euclid(self.capacity as i32) as usize
    }

    fn hash2(&self, key: i32) -> usize {
        self.prime - (key.rem_euclid(self.prime as i32) as usize)
    }

    pub fn insert(&mut self, key: i32, value: i32) {
        if self.size == self.capacity {
            return;
        }
        let mut index = self.hash1(key);
        let step = self.hash2(key);

        while let Some(ref item) = self.table[index] {
            if !item.deleted && item.key == key {
                break;
            }
            if item.deleted {
                break;
            }
            index = (index + step) % self.capacity;
        }

        if self.table[index].is_none() || self.table[index].as_ref().unwrap().deleted {
            self.size += 1;
        }
        self.table[index] = Some(DoubleHashItem {
            key,
            value,
            deleted: false,
        });
    }

    pub fn search(&self, key: i32) -> Option<i32> {
        let mut index = self.hash1(key);
        let step = self.hash2(key);
        let start_index = index;

        while let Some(ref item) = self.table[index] {
            if !item.deleted && item.key == key {
                return Some(item.value);
            }
            index = (index + step) % self.capacity;
            if index == start_index {
                break;
            }
        }
        None
    }

    pub fn remove(&mut self, key: i32) {
        let mut index = self.hash1(key);
        let step = self.hash2(key);
        let start_index = index;

        while let Some(ref mut item) = self.table[index] {
            if !item.deleted && item.key == key {
                item.deleted = true;
                self.size -= 1;
                return;
            }
            index = (index + step) % self.capacity;
            if index == start_index {
                break;
            }
        }
    }
}

pub struct StackArray {
    arr: Vec<i32>,
    capacity: usize,
}

impl StackArray {
    pub fn new(capacity: usize) -> Self {
        StackArray {
            arr: Vec::with_capacity(capacity),
            capacity,
        }
    }

    pub fn push(&mut self, value: i32) {
        if self.arr.len() < self.capacity {
            self.arr.push(value);
        }
    }

    pub fn pop(&mut self) -> Option<i32> {
        self.arr.pop()
    }

    pub fn peek(&self) -> Option<&i32> {
        self.arr.last()
    }

    pub fn is_empty(&self) -> bool {
        self.arr.is_empty()
    }

    pub fn size(&self) -> usize {
        self.arr.len()
    }
}

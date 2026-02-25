pub struct QueueArray {
    arr: Vec<Option<i32>>,
    front: usize,
    rear: usize,
    capacity: usize,
    size: usize,
}

impl QueueArray {
    pub fn new(capacity: usize) -> Self {
        QueueArray {
            arr: vec![None; capacity],
            front: 0,
            rear: capacity - 1,
            capacity,
            size: 0,
        }
    }

    pub fn is_empty(&self) -> bool {
        self.size == 0
    }

    pub fn is_full(&self) -> bool {
        self.size == self.capacity
    }

    pub fn enqueue(&mut self, value: i32) {
        if self.is_full() {
            return;
        }
        self.rear = (self.rear + 1) % self.capacity;
        self.arr[self.rear] = Some(value);
        self.size += 1;
    }

    pub fn dequeue(&mut self) -> Option<i32> {
        if self.is_empty() {
            return None;
        }
        let value = self.arr[self.front];
        self.arr[self.front] = None;
        self.front = (self.front + 1) % self.capacity;
        self.size -= 1;
        value
    }

    pub fn peek(&self) -> Option<&i32> {
        if self.is_empty() {
            return None;
        }
        self.arr[self.front].as_ref()
    }
}

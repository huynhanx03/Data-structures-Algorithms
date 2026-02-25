pub struct MinHeap {
    arr: Vec<i32>,
}

impl MinHeap {
    pub fn new() -> Self {
        MinHeap { arr: Vec::new() }
    }

    pub fn insert(&mut self, val: i32) {
        self.arr.push(val);
        self.heapify_up(self.arr.len() - 1);
    }

    pub fn extract_min(&mut self) -> Option<i32> {
        if self.arr.is_empty() {
            return None;
        }
        let min = self.arr[0];
        let last = self.arr.pop().unwrap();
        if !self.arr.is_empty() {
            self.arr[0] = last;
            self.heapify_down(0);
        }
        Some(min)
    }

    fn heapify_up(&mut self, mut index: usize) {
        while index > 0 {
            let parent = (index - 1) / 2;
            if self.arr[index] < self.arr[parent] {
                self.arr.swap(index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }

    fn heapify_down(&mut self, mut index: usize) {
        loop {
            let left = 2 * index + 1;
            let right = 2 * index + 2;
            let mut smallest = index;

            if left < self.arr.len() && self.arr[left] < self.arr[smallest] {
                smallest = left;
            }
            if right < self.arr.len() && self.arr[right] < self.arr[smallest] {
                smallest = right;
            }
            if smallest != index {
                self.arr.swap(index, smallest);
                index = smallest;
            } else {
                break;
            }
        }
    }
}

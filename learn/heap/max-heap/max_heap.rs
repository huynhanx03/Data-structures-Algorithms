pub struct MaxHeap {
    arr: Vec<i32>,
}

impl MaxHeap {
    pub fn new() -> Self {
        MaxHeap { arr: Vec::new() }
    }

    pub fn insert(&mut self, val: i32) {
        self.arr.push(val);
        self.heapify_up(self.arr.len() - 1);
    }

    pub fn extract_max(&mut self) -> Option<i32> {
        if self.arr.is_empty() {
            return None;
        }
        let max = self.arr[0];
        let last = self.arr.pop().unwrap();
        if !self.arr.is_empty() {
            self.arr[0] = last;
            self.heapify_down(0);
        }
        Some(max)
    }

    fn heapify_up(&mut self, mut index: usize) {
        while index > 0 {
            let parent = (index - 1) / 2;
            if self.arr[index] > self.arr[parent] {
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
            let mut largest = index;

            if left < self.arr.len() && self.arr[left] > self.arr[largest] {
                largest = left;
            }
            if right < self.arr.len() && self.arr[right] > self.arr[largest] {
                largest = right;
            }
            if largest != index {
                self.arr.swap(index, largest);
                index = largest;
            } else {
                break;
            }
        }
    }
}

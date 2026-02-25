use std::cell::RefCell;
use std::rc::Rc;

pub struct QueueNode {
    pub data: i32,
    pub next: Option<Rc<RefCell<QueueNode>>>,
}

pub struct QueueLinkedList {
    front: Option<Rc<RefCell<QueueNode>>>,
    rear: Option<Rc<RefCell<QueueNode>>>,
}

impl QueueLinkedList {
    pub fn new() -> Self {
        QueueLinkedList {
            front: None,
            rear: None,
        }
    }

    pub fn is_empty(&self) -> bool {
        self.front.is_none()
    }

    pub fn enqueue(&mut self, value: i32) {
        let new_node = Rc::new(RefCell::new(QueueNode {
            data: value,
            next: None,
        }));
        match self.rear.take() {
            Some(old_rear) => {
                old_rear.borrow_mut().next = Some(new_node.clone());
                self.rear = Some(new_node);
            }
            None => {
                self.front = Some(new_node.clone());
                self.rear = Some(new_node);
            }
        }
    }

    pub fn dequeue(&mut self) -> Option<i32> {
        self.front.take().map(|old_front| {
            let next = old_front.borrow_mut().next.take();
            self.front = next;
            if self.front.is_none() {
                self.rear = None;
            }
            old_front.borrow().data
        })
    }

    pub fn peek(&self) -> Option<i32> {
        self.front.as_ref().map(|node| node.borrow().data)
    }
}

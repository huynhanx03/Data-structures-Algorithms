use std::cell::RefCell;
use std::rc::Rc;

pub struct DNode {
    pub data: i32,
    pub prev: Option<Rc<RefCell<DNode>>>,
    pub next: Option<Rc<RefCell<DNode>>>,
}

pub struct DoublyLinkedList {
    pub head: Option<Rc<RefCell<DNode>>>,
    pub tail: Option<Rc<RefCell<DNode>>>,
}

impl DoublyLinkedList {
    pub fn new() -> Self {
        DoublyLinkedList {
            head: None,
            tail: None,
        }
    }

    pub fn insert_at_end(&mut self, data: i32) {
        let new_node = Rc::new(RefCell::new(DNode {
            data,
            prev: self.tail.clone(),
            next: None,
        }));

        match self.tail.take() {
            Some(old_tail) => {
                old_tail.borrow_mut().next = Some(new_node.clone());
                self.tail = Some(new_node);
            }
            None => {
                self.head = Some(new_node.clone());
                self.tail = Some(new_node);
            }
        }
    }

    pub fn delete_node(&mut self, key: i32) {
        let mut curr = self.head.clone();
        while let Some(node) = curr {
            if node.borrow().data == key {
                let prev = node.borrow().prev.clone();
                let next = node.borrow().next.clone();

                if let Some(ref p) = prev {
                    p.borrow_mut().next = next.clone();
                } else {
                    self.head = next.clone();
                }

                if let Some(ref n) = next {
                    n.borrow_mut().prev = prev.clone();
                } else {
                    self.tail = prev.clone();
                }
                return;
            }
            let next_node = node.borrow().next.clone();
            curr = next_node;
        }
    }

    pub fn search(&self, key: i32) -> bool {
        let mut curr = self.head.clone();
        while let Some(node) = curr {
            if node.borrow().data == key {
                return true;
            }
            let next_node = node.borrow().next.clone();
            curr = next_node;
        }
        false
    }
}

pub struct Node {
    pub data: i32,
    pub next: Option<Box<Node>>,
}

pub struct SinglyLinkedList {
    pub head: Option<Box<Node>>,
}

impl SinglyLinkedList {
    pub fn new() -> Self {
        SinglyLinkedList { head: None }
    }

    pub fn insert_at_end(&mut self, data: i32) {
        let new_node = Box::new(Node { data, next: None });
        let mut curr = &mut self.head;
        while let Some(ref mut node) = curr {
            curr = &mut node.next;
        }
        *curr = Some(new_node);
    }

    pub fn delete_node(&mut self, key: i32) {
        let mut curr = &mut self.head;
        loop {
            match curr {
                Some(node) if node.data == key => {
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

    pub fn search(&self, key: i32) -> bool {
        let mut curr = &self.head;
        while let Some(node) = curr {
            if node.data == key {
                return true;
            }
            curr = &node.next;
        }
        false
    }
}

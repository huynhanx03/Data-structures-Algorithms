pub struct StackNode {
    data: i32,
    next: Option<Box<StackNode>>,
}

pub struct StackLinkedList {
    top: Option<Box<StackNode>>,
}

impl StackLinkedList {
    pub fn new() -> Self {
        StackLinkedList { top: None }
    }

    pub fn push(&mut self, value: i32) {
        let new_node = Box::new(StackNode {
            data: value,
            next: self.top.take(),
        });
        self.top = Some(new_node);
    }

    pub fn pop(&mut self) -> Option<i32> {
        self.top.take().map(|node| {
            self.top = node.next;
            node.data
        })
    }

    pub fn peek(&self) -> Option<&i32> {
        self.top.as_ref().map(|node| &node.data)
    }

    pub fn is_empty(&self) -> bool {
        self.top.is_none()
    }
}

pub struct Node {
    pub data: i32,
    pub left: Option<Box<Node>>,
    pub right: Option<Box<Node>>,
}

pub struct BinaryTree {
    pub root: Option<Box<Node>>,
}

impl BinaryTree {
    pub fn new() -> Self {
        BinaryTree { root: None }
    }

    pub fn pre_order(&self, node: &Option<Box<Node>>, result: &mut Vec<i32>) {
        if let Some(ref n) = node {
            result.push(n.data);
            self.pre_order(&n.left, result);
            self.pre_order(&n.right, result);
        }
    }

    pub fn in_order(&self, node: &Option<Box<Node>>, result: &mut Vec<i32>) {
        if let Some(ref n) = node {
            self.in_order(&n.left, result);
            result.push(n.data);
            self.in_order(&n.right, result);
        }
    }

    pub fn post_order(&self, node: &Option<Box<Node>>, result: &mut Vec<i32>) {
        if let Some(ref n) = node {
            self.post_order(&n.left, result);
            self.post_order(&n.right, result);
            result.push(n.data);
        }
    }
}

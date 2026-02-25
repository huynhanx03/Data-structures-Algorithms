pub struct BSTNode {
    pub data: i32,
    pub left: Option<Box<BSTNode>>,
    pub right: Option<Box<BSTNode>>,
}

pub struct BinarySearchTree {
    pub root: Option<Box<BSTNode>>,
}

impl BinarySearchTree {
    pub fn new() -> Self {
        BinarySearchTree { root: None }
    }

    pub fn insert(&mut self, data: i32) {
        if let Some(ref mut node) = self.root {
            Self::insert_node(node, data);
        } else {
            self.root = Some(Box::new(BSTNode {
                data,
                left: None,
                right: None,
            }));
        }
    }

    fn insert_node(node: &mut Box<BSTNode>, data: i32) {
        if data < node.data {
            if let Some(ref mut left) = node.left {
                Self::insert_node(left, data);
            } else {
                node.left = Some(Box::new(BSTNode {
                    data,
                    left: None,
                    right: None,
                }));
            }
        } else {
            if let Some(ref mut right) = node.right {
                Self::insert_node(right, data);
            } else {
                node.right = Some(Box::new(BSTNode {
                    data,
                    left: None,
                    right: None,
                }));
            }
        }
    }

    pub fn search(&self, data: i32) -> bool {
        Self::search_node(&self.root, data)
    }

    fn search_node(node: &Option<Box<BSTNode>>, data: i32) -> bool {
        if let Some(ref n) = node {
            if data < n.data {
                return Self::search_node(&n.left, data);
            } else if data > n.data {
                return Self::search_node(&n.right, data);
            } else {
                return true;
            }
        }
        false
    }
}

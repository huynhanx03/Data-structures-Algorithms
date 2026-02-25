use std::cmp;

pub struct AVLNode {
    pub data: i32,
    pub height: i32,
    pub left: Option<Box<AVLNode>>,
    pub right: Option<Box<AVLNode>>,
}

pub struct AVLTree {
    pub root: Option<Box<AVLNode>>,
}

impl AVLTree {
    pub fn new() -> Self {
        AVLTree { root: None }
    }

    fn height(node: &Option<Box<AVLNode>>) -> i32 {
        node.as_ref().map_or(0, |n| n.height)
    }

    fn update_height(node: &mut AVLNode) {
        node.height = 1 + cmp::max(Self::height(&node.left), Self::height(&node.right));
    }

    fn rotate_right(mut y: Box<AVLNode>) -> Box<AVLNode> {
        let mut x = y.left.take().unwrap();
        y.left = x.right.take();
        Self::update_height(&mut y);
        x.right = Some(y);
        Self::update_height(&mut x);
        x
    }

    fn rotate_left(mut x: Box<AVLNode>) -> Box<AVLNode> {
        let mut y = x.right.take().unwrap();
        x.right = y.left.take();
        Self::update_height(&mut x);
        y.left = Some(x);
        Self::update_height(&mut y);
        y
    }

    pub fn insert(&mut self, data: i32) {
        self.root = Self::insert_node(self.root.take(), data);
    }

    fn insert_node(node: Option<Box<AVLNode>>, data: i32) -> Option<Box<AVLNode>> {
        let mut node = match node {
            None => {
                return Some(Box::new(AVLNode {
                    data,
                    height: 1,
                    left: None,
                    right: None,
                }))
            }
            Some(n) => n,
        };

        if data < node.data {
            node.left = Self::insert_node(node.left.take(), data);
        } else if data > node.data {
            node.right = Self::insert_node(node.right.take(), data);
        } else {
            return Some(node);
        }

        Self::update_height(&mut node);
        let balance = Self::height(&node.left) - Self::height(&node.right);

        if balance > 1 {
            let left_bal = node
                .left
                .as_ref()
                .map_or(0, |l| Self::height(&l.left) - Self::height(&l.right));
            if left_bal < 0 {
                node.left = Some(Self::rotate_left(node.left.take().unwrap()));
            }
            return Some(Self::rotate_right(node));
        }

        if balance < -1 {
            let right_bal = node
                .right
                .as_ref()
                .map_or(0, |r| Self::height(&r.left) - Self::height(&r.right));
            if right_bal > 0 {
                node.right = Some(Self::rotate_right(node.right.take().unwrap()));
            }
            return Some(Self::rotate_left(node));
        }

        Some(node)
    }
}

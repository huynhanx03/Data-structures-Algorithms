/*
 Problem: 1079. Sum of Root To Leaf Binary Numbers
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2.3 MB (26.45%)
 Tags: Tree, Depth-First Search, Binary Tree
*/
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    fn dfs(node: Option<Rc<RefCell<TreeNode>>>, cur: i32) -> i32 {
        if let Some(n) = node {
            let n_ref = n.borrow();
            let val = (cur << 1) | n_ref.val;

            if n_ref.left.is_none() && n_ref.right.is_none() {
                return val;
            }

            Solution::dfs(n_ref.left.clone(), val) +
            Solution::dfs(n_ref.right.clone(), val)
        } else {
            0
        }
    }

    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Solution::dfs(root, 0)
    }
}
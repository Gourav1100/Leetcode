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
    pub fn balance_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        fn dfs1(n: &Option<Rc<RefCell<TreeNode>>>, sorted: &mut Vec<i32>) {
            let Some(n) = n.as_ref() else { return; };
            let n = n.borrow();
            dfs1(&n.left, sorted);
            sorted.push(n.val);
            dfs1(&n.right, sorted)
        }
        fn dfs2(sorted: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
            if sorted.len() < 1 { return None };
            let mid = sorted.len() / 2;
            let left = dfs2(&sorted[..mid]);
            let right = dfs2(&sorted[mid + 1..]);
            Some(Rc::new(RefCell::new(TreeNode { val: sorted[mid], left: left, right: right })))
        }
        let mut sorted = vec![];
        dfs1(&root, &mut sorted);
        dfs2(&sorted[..])
    }
}
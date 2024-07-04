// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut current = 0;
        let mut current_node = head.to_owned();
        let mut sums: Vec<i32> = Vec::new();
        while let Some(node) = current_node {
            if (*node).val == 0 {
                if current != 0 {
                    sums.push(current.to_owned());
                }
                current = 0;
            } else {
                current += (*node).val;
            }
            current_node = (*node).next;
        }
        if sums.len() == 0 {
            return None;
        }
        let mut res_head = Some(Box::new(ListNode::new(sums[0])));
        let mut res = res_head.as_deref_mut();
        for index in 1..sums.len() {
            if let Some(mut node) = res {
                (*node).next = Some(Box::new(ListNode::new(sums[index])));
                res = (*node).next.as_deref_mut();
            }
        }
        res_head
    }
}
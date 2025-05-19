// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]

pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

pub struct Solution {}

impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {

        let mut dummy = Box::new(ListNode { val: 0, next: head });
        let mut len = 0;
        let mut curr = &dummy.next;
        while let Some(node) = curr {
            len += 1;
            curr = &node.next;
        }

        let pos = len - n;
        let mut curr = &mut dummy;
        for _ in 0..pos {
            curr = curr.next.as_mut().unwrap();
        }

        if let Some(mut removee) = curr.next.take() {
            curr.next = removee.next.take();
        }

        dummy.next

    }
}
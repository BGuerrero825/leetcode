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

    pub fn create_list(size: i32) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut curr = &mut dummy;
        for i in 0..size {
            // curr is a ref to a mutable (Boxed) ListNode: change the referenced Node's 'next' field
            // by setting it to a newly alloced (Optional + Boxed) ListNode
            curr.next = Some(Box::new(ListNode::new(i)));
            // curr is also itself mutable: change curr to reference 'next's (Opt + Boxed) ListNode
            // BUT, curr needs a reference to a mutable Boxed ListNode, not a mutable REFERENCE to
            // an Optional + Boxed ListNode. So, as_mut() adjusts the mutability target to the
            // Boxed ListNode contained within the Optional, making the assignment valid.
            curr = curr.next.as_mut()?;
        }

        dummy.next
    }

    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
      let mut dummy = Box::new(ListNode{val: 0, next: head});
      let mut curr = &dummy.next;
      let mut len = 1;

      while let Some(node) = curr {
        curr = &node.next;
        len += 1;
      }

      let remove_index = len - n;
      let mut curr = &mut dummy;
      for _ in 0..remove_index {
        curr = curr.next.as_mut()?;
      }

      if let Some(removee) = curr.next.clone() {
        curr.next = removee.next
      }

      dummy.next
    }

/* 
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
            curr = curr.next.as_mut()?;
        }

        if let Some(mut removee) = curr.next.take() {
            curr.next = removee.next.take();
        }

        dummy.next

    }

*/

}
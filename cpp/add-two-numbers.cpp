/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* head = new ListNode();
        ListNode* node = head;
        while(l1 || l2 || carry) {
            int l1val = l1 ? l1->val : 0;
            int l2val = l2 ? l2->val : 0;
            int nodeval = l1val + l2val;
            if (carry) {
                nodeval += 1;
                carry = false;
            }
            if (nodeval >= 10) {
                nodeval -= 10;
                carry = true;
            }
            ListNode* newNode = new ListNode(nodeval);
            node->next = newNode;
            node = newNode;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        return head->next;
    }
};
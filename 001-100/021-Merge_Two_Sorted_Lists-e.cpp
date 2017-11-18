// Merge two sorted linked lists and return it as a new list. The new list
// should be made by splicing together the nodes of the first two lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode l3val(0);
        ListNode *l3 = &l3val;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        l3->next = l1 ? l1 : l2;
        return l3val.next; // first one is not we want
    }
};
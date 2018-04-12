// Given a list, rotate the list to the right by k places, where k is
// non-negative.

// Example:

// Given 1->2->3->4->5->NULL and k = 2,

// return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head)
            return head;

        int len = 1;
        ListNode *tail = head;
        while (tail->next) {
            ++len;
            tail = tail->next;
        }
        tail->next = head;

        k = len - k % len;

        while (k) {
            --k;
            tail = tail->next;
        }
        head = tail->next; // new head
        tail->next = NULL; // new tail

        return head;
    }
};
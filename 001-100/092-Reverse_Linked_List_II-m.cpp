//  Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int i = 1;
        ListNode **pphead = &head;

        while (i < m) {
            ++i;
            pphead = &(*pphead)->next;
        }

        // *pphead is prev->next, ost is the start node
        ListNode *st = *pphead, *ost = st;

        ListNode *dummy = NULL;
        while (i <= n) {
            ++i;
            swap(st->next, dummy);
            swap(dummy, st);
        }
        // now dummy is the head of reversed list, st is the other part head

        *pphead = dummy;
        ost->next = st;

        return head;
    }
};
// Given a linked list, reverse the nodes of a linked list k at a time and
// return its modified list.

// k is a positive integer and is less than or equal to the length of the linked
// list. If the number of nodes is not a multiple of k then left-out nodes in
// the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be
// changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool check(ListNode *head, int k) {
        for (int i = 0; i < k - 1; ++i)
            if (head)
                head = head->next;
            else
                break;
        return head;
    }

    // also move head; return new head
    ListNode *reverseK(ListNode *&head, int k) {
        ListNode *temp = nullptr;
        for (int i = 0; i < k; ++i) {
            swap(temp, head->next);
            swap(temp, head);
        }
        return temp;
    };

  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!check(head, k))
            return head;

        ListNode *prev_head = head, *ret = reverseK(head, k);

        while (check(head, k)) {
            ListNode *curr_head = head;
            prev_head->next = reverseK(head, k);
            prev_head = curr_head;
        }

        prev_head->next = head; // rest of list or NULL

        return ret;
    }
};
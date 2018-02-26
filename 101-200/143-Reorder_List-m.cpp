//  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *revList(ListNode *head) {
        ListNode *temp = NULL;
        while (head) {
            swap(head->next, temp);
            swap(head, temp);
        }
        return temp;
    }

  public:
    void reorderList(ListNode *head) {
        if (!head)
            return;

        // break list to 2 half
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rhead = slow->next;
        slow->next = NULL;

        // reverse right half (shorter)
        rhead = revList(rhead);

        slow = head;
        while (slow) {
            swap(slow->next, rhead);
            slow = slow->next;
        }

        return;
    }
};
// Given a linked list, determine if it has a cycle in it.
// Follow up:
// Can you solve it without using extra space?

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
    bool hasCycle(ListNode *head) {
        if (!head)
            return 0;
        ListNode *slow = head, *fast = head;
        while ((slow = slow->next) && fast->next && (fast = fast->next->next))
            if (slow == fast)
                return 1;
        return 0;
    }
};
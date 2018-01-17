// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test
// cases.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// traditional recursive method
class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head)
            return NULL;

        head->next = removeElements(head->next, val);

        return head->val == val ? head->next : head;
    }
};

// double pointer
class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        auto *pp = &head; // pp is pointer to (ListNode *)

        while (*pp)
            // -> has higher precedence than *
            if ((*pp)->val == val)
                *pp = (*pp)->next;
            else
                pp = &(*pp)->next;

        return head;
    }
};
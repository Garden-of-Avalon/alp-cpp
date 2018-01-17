//  Given a sorted linked list, delete all duplicates such that each element
//  appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// actually double pointer is not needed
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto *pp = &head;
        while(*pp && (*pp)->next) {
            if((*pp)->val == (*pp)->next->val)
                (*pp)->next = (*pp)->next->next;
            else
                pp = &(*pp)->next;
        }
        return head;
    }
};
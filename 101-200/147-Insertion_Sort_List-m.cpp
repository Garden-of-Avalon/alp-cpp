// Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        auto *newhead = new ListNode(INT_MIN);

        while (head) {
            auto *insertnode = head;
            head = head->next;

            auto **pp = &newhead;
            while (*pp && (*pp)->val < insertnode->val)
                pp = &(*pp)->next;
            insertnode->next = *pp;
            *pp = insertnode;
        }

        return newhead->next;
    }
};

class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode new_head = ListNode(0);

        ListNode *curr = head, *prev, *currnext;

        while (curr) {
            prev = &new_head;
            while (prev->next && prev->next->val < curr->val)
                prev = prev->next;

            currnext = curr->next;

            // insert between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            //  move curr
            curr = currnext;
        }

        return new_head.next;
    }
};
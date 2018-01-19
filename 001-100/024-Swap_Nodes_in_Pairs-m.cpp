//  Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values
// in the list, only nodes itself can be changed.

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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !(head->next))
            return head;

        auto *newhead = head->next, *curr = head;

        while (curr && curr->next) {
            auto *temp = curr->next;
            curr->next = temp->next;
            temp->next = curr;
            curr = curr->next;
            if (curr && curr->next)
                temp->next->next = curr->next;
        }

        return newhead;
    }
};

// recursive, not constant space
class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !(head->next))
            return head;

        auto *newhead = head->next, *curr = head;

        curr->next = swapPairs(newhead->next);
        newhead->next = curr;

        return newhead;
    }
};

// simplify
class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *curr = head, **pp = &head;
        while (curr && curr->next) {
            *pp = curr->next;
            swap(curr, (*pp)->next);
            (*pp)->next->next = curr;
            pp = &(*pp)->next->next;
            // pp now is &(last node of current part)->next
        }
        return head;
    }
};
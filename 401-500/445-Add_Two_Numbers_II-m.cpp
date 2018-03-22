// You are given two non-empty linked lists representing two non-negative
// integers. The most significant digit comes first and each of their nodes
// contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the
// lists is not allowed.

// Example:

// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *revList(ListNode *L) {
        ListNode *temp = nullptr;
        while (L) {
            swap(L->next, temp);
            swap(L, temp);
        }
        return temp;
    }

  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        l1 = revList(l1), l2 = revList(l2);

        ListNode *ret = nullptr;
        ListNode **retptr = &ret;
        int carry = 0;
        while (l1 || l2 || carry) {
            int currsum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = currsum / 10;
            *retptr = new ListNode(currsum % 10);

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            retptr = &(*retptr)->next;
        }

        return revList(ret);
    }
};
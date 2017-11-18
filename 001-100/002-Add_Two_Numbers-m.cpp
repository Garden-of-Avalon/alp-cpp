// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order and each of their nodes
// contain a single digit.
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode *result = NULL, *restemp = NULL;
        int carry = 0, tempdigit = 0;
        while (!(temp1 == NULL && temp2 == NULL && carry == 0)) {
            tempdigit = (temp1 == NULL ? 0 : temp1->val) +
                        (temp2 == NULL ? 0 : temp2->val) + carry;
            // if tempdigit > 9, carry == 1 else carry == 0.
            carry = tempdigit / 10;

            temp1 = temp1 != NULL ? temp1->next : NULL;
            temp2 = temp2 != NULL ? temp2->next : NULL;

            if (restemp) {
                restemp->next = new ListNode(tempdigit % 10);
                restemp = restemp->next;
            } else {
                result = new ListNode(tempdigit % 10); // first node
                restemp = result;
            }
        }
        return result;
    }
};
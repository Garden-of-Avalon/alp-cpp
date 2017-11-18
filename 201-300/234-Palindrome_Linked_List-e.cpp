// Given a singly linked list, determine if it is a palindrome.
// Follow up:
// Could you do it in O(n) time and O(1) space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// just follow regular reverse list method
// ref 206
class Solution {
    ListNode *reverseList(ListNode *head) {
        ListNode *temp = NULL;
        while (head) {
            std::swap(temp, head->next);
            std::swap(head, temp);
        }
        return temp;
    }

  public:
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow);
        while (slow) {
            if (slow->val != head->val)
                return 0;
            slow = slow->next;
            head = head->next;
        }
        return 1;
    }
};
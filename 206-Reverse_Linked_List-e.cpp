// Reverse a singly linked list.
// click to show more hints.
// Hint:
// A linked list can be reversed either iteratively or recursively. Could you
// implement both?

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
    ListNode *reverseList(ListNode *head) {
        if (!head)
            return head;
        ListNode *temp = NULL;
        while (head) {
            std::swap(temp, head->next);
            std::swap(head, temp);
        }
        return temp;
    }
};

// recursive version
// class Solution {
//     ListNode *reversehelper(ListNode *head, ListNode *end) {
//         std::swap(head->next, end);
//         if (!end)
//             return head;
//         return reversehelper(end, head);
//     }

//   public:
//     ListNode *reverseList(ListNode *head) {
//         if (!head)
//             return head;
//         return reversehelper(head, NULL);
//     }
// };
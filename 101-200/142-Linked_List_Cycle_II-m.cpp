//  Given a linked list, return the node where the cycle begins. If there is no
//  cycle, return null.

// Note: Do not modify the linked list.

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
// O(n), O(n)
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> nodes;

        while (head) {
            if (!nodes.insert(head).second)
                return head;
            head = head->next;
        }

        return head;
    }
};

// O(n), O(1); Floyd's Tortoise and Hare
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        decltype(head) slow, fast, finder;
        slow = fast = finder = head;

        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast && fast && fast->next);

        if (slow != fast)
            return NULL;

        while (slow != finder) {
            slow = slow->next;
            finder = finder->next;
        }

        return finder;
    }
};
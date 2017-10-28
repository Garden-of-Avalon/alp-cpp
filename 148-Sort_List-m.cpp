// Sort a linked list in O(n log n) time using constant space complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *merge(ListNode *h1, ListNode *h2) {
        ListNode helper(0);
        ListNode *l3 = &helper;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                l3->next = h1;
                h1 = h1->next;
            } else {
                l3->next = h2;
                h2 = h2->next;
            }
            l3 = l3->next;
        }
        l3->next = h1 ? h1 : h2;
        return helper.next;
    }

  public:
    ListNode *sortList(ListNode *head) {
        if (!head)
            return head;

        // break list nodes
        deque<ListNode *> working;
        while (head) {
            working.push_back(head);
            head = head->next;
            working.back()->next = NULL;
        }

        // sorting
        ListNode *l1, *l2;
        while (working.size() > 1) {
            l1 = working.front();
            working.pop_front();
            l2 = working.front();
            working.pop_front();
            working.push_back(merge(l1, l2));
        }

        return working.front();
    }
};
// Merge k sorted linked lists and return it as one sorted list. Analyze and
// describe its complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *merge2(ListNode *l1, ListNode *l2) {
        // can move to outer scope
        // if not perform parallelling
        ListNode l3node(0);
        ListNode *l3 = &l3node;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        l3->next = l1 ? l1 : l2;
        return l3node.next;
    }

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        std::deque<ListNode *> mergeq(lists.begin(), lists.end());
        ListNode *l1, *l2;
        while (mergeq.size() > 1) {
            l1 = mergeq.front();
            mergeq.pop_front();
            l2 = mergeq.front();
            mergeq.pop_front();
            mergeq.push_back(merge2(l1, l2));
        }
        return mergeq.front();
    }
};
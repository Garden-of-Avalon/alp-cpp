// Sort a linked list in O(n log n) time using constant space complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// True O(1), no recursion
class Solution {
    pair<ListNode *, ListNode *> merge(ListNode *h1, ListNode *h2) {
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
        while (l3->next)
            l3 = l3->next;
        return make_pair(helper.next, l3); // new list head and tail
    }

    ListNode *splitk(ListNode *head, int k) {
        if (!head)
            return head;
        for (int i = 0; i < k - 1; ++i) {
            if (!head->next)
                break;
            head = head->next;
        }
        ListNode *newhead = head->next;
        head->next = NULL;
        return newhead;
    }

    // void print(ListNode *l) {
    //     while (l) {
    //         cout << l->val << ' ';
    //         l = l->next;
    //     }
    //     cout << endl;
    // }

  public:
    ListNode *sortList(ListNode *head) {
        if (!head)
            return head;

        ListNode temp(0);
        pair<ListNode *, ListNode *> dummy{&temp, &temp}, prev_sorted = dummy;

        int step = 1, cnt = 0;
        while (true) {
            while (head) {
                auto l1 = head;
                auto l2 = splitk(l1, step);
                head = splitk(l2, step);

                // now l2 length <= l1 length <= step;

                auto sorted = merge(l1, l2);
                prev_sorted.second->next = sorted.first;
                prev_sorted = sorted;

                ++cnt;
            }

            // 1 merge, must be last merge
            if (cnt == 1)
                return temp.next;

            // prepare for next round
            cnt = 0;
            step *= 2;
            head = temp.next;
            prev_sorted = dummy;
        }
        // won't go to this line
    }
};

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
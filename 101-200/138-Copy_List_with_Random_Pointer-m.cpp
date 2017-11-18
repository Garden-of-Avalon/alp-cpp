// A linked list is given such that each node contains an additional random
// pointer which could point to any node in the list or null.
// Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return head;

        // 1st loop, duplicate every node in original list
        RandomListNode *t1, *t2;
        for (t1 = head; t1; t1 = t1->next->next) {
            t2 = new RandomListNode(t1->label);
            t2->next = t1->next;
            t1->next = t2;
        }

        // 2nd loop, solving Random
        for (t1 = head; t1; t1 = t1->next->next) {
            if (t1->random)
                t1->next->random = t1->random->next;
        }

        // 3rd loop, break list
        RandomListNode *newhead = head->next;
        t1 = head, t2 = newhead;
        while (t1) {
            t1->next = t2->next;
            if (!(t1->next))
                break;
            t1 = t1->next;
            t2->next = t1->next;
            t2 = t2->next;
        }

        return newhead;
    }
};
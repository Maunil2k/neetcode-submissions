/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode *s = head;
        ListNode *f = s->next;
        if (!f) return false;
        if (!f->next) return false;
        f = f->next;
        while(f) {
            if (f == s) return true;
            else {
                s = s->next;
                if (f->next && f->next->next) {
                    f = f->next->next;
                }
                else {
                    f = nullptr;
                }
            }
        }
        return false;
    }
};

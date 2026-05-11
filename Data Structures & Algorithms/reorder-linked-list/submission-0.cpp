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
    void reorderList(ListNode* head) {
        ListNode *s = head;
        ListNode *f = s->next;
            while (f && f->next) {
                s = s->next;
                f = f->next->next;
            }
            ListNode *second = s->next;

            // reverse the second LL
            ListNode *prev = s->next = nullptr;
            while (second) {
                ListNode *tmp = second -> next;
                second->next = prev;
                prev = second;
                second = tmp;                
            }

            ListNode *first = head;
            second = prev;
            while (second) {
                ListNode *tmp1 = first->next;
                ListNode *tmp2 = second->next;
                first->next = second;
                second->next = tmp1;
                first = tmp1; 
                second = tmp2; 
            }
    }
};

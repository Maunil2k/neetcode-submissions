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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. reverse the LL
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        // 2. pop the nth element
        if (n == 1) prev = prev->next;
        else {
            ListNode *tmp = prev;
            for (int i = 1; i<n-1; i++) tmp = tmp -> next;
            if (tmp -> next) tmp -> next = tmp -> next -> next;
            else tmp -> next = nullptr;
        }
        // 3. reverse the LL again to get back the original LL.
        ListNode *ncurr = prev;
        ListNode *nprev = nullptr;
        while (ncurr) {
            ListNode *tmp = ncurr->next;
            ncurr->next = nprev;
            nprev = ncurr;
            ncurr = tmp;
        }

        return nprev;
    }
};

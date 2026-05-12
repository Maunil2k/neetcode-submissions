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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* prev1 = nullptr;
        int n1 = 0, val1=0;
        while (curr1) {
            ListNode *tmp = curr1->next;
            curr1->next = prev1;
            prev1 = curr1;
            curr1 = tmp;
            n1++;
        }
        cout << n1 << endl;
        for(int i=n1-1; i>=0; i--) {
            val1+= (prev1->val) * pow(10, i);
            prev1 = prev1->next;
        }
        cout << val1 <<endl;
        ListNode* curr2 = l2;
        ListNode* prev2 = nullptr;
        int n2 = 0, val2=0;
        while (curr2) {
            ListNode *tmp = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = tmp;
            n2++;
        }
        cout << n2 << endl;
        for(int i=n2-1; i>=0; i--) {
            val2 += (prev2->val) * pow(10, i);
            prev2 = prev2->next;
        }
        cout << val2 << endl;

        int total = val1 + val2;
        cout << "Sum of two LLs " << total <<endl; 
        ListNode *ans = new ListNode(0);
        ListNode *tmp = ans;
        while (total) {
            tmp -> val = total % 10;
            total /= 10;
            if (total) tmp->next = new ListNode(0);
            else tmp -> next = nullptr;
            tmp = tmp -> next;
        }
        return ans;
    }
};

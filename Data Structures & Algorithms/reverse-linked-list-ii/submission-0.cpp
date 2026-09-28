class Solution {
private:
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        // Find the node before position left
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Find the node at position left
        ListNode* leftNode = prev->next;

        // Find the node at position right
        ListNode* rightNode = leftNode;
        for (int i = left; i < right; i++) {
            rightNode = rightNode->next;
        }

        // Save node after position right
        ListNode* next = rightNode->next;

        // Disconnect the sublist
        rightNode->next = nullptr;

        // Reverse [left, right]
        prev->next = reverseLL(leftNode);

        // Find the new tail of reversed portion
        while (prev->next) {
            prev = prev->next;
        }

        // Reconnect
        prev->next = next;

        return dummy.next;
    }
};
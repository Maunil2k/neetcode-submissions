/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copy;
        copy[NULL] = NULL;

        Node *curr = head;
        while(curr) {
            Node *tmp = new Node(curr->val);
            copy[curr] = tmp;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            Node *tmp = copy[curr];
            tmp->next = copy[curr->next];
            tmp->random = copy[curr->random];
            curr = curr->next;
        }
        return copy[head];
    }
};

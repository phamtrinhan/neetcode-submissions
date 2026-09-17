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
        if (!head) return nullptr;

        for (Node* cur = head; cur; cur = cur->next->next) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
        }

        for (Node* cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;

        Node* res = head->next;

        for (Node* cur = head; cur;) {
            Node* copy = cur->next;
            cur->next = copy->next;
            copy->next = copy->next ? copy->next->next : nullptr;
            cur = cur->next;
        }

        return res;
    }
};
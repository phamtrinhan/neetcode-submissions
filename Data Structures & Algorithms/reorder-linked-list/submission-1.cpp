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
        if (!head || !head->next) return;

        // Tìm điểm giữa của danh sách liên kết
        ListNode* mid = findMiddle(head);

        // Đảo ngược nửa sau của danh sách liên kết
        ListNode* l1 = head;
        ListNode* l2 = reverseList(mid->next);
        mid->next = nullptr;

        // Kết hợp hai nửa danh sách liên kết
        mergeLists(l1, l2);
    }

private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeLists(ListNode* l1, ListNode* l2) {
        while (l2) {
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;
            l1->next = l2;
            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }
};



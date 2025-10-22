
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
    ListNode* removeElements(ListNode* head, int val) {
        // Remove leading nodes with value = val
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        // Traverse and remove subsequent nodes
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val == val) {
                curr->next = curr->next->next; // skip node
            } else {
                curr = curr->next; // move ahead
            }
        }

        return head;
    }
};

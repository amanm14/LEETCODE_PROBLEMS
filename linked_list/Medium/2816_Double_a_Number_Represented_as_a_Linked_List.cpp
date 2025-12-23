class Solution {
public://O(N) tc and  sc is O(1)
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        int carry = 0;
        ListNode* curr = head;
        ListNode* tail = NULL;

        while (curr) {
            int sum = curr->val * 2 + carry;
            curr->val = sum % 10;
            carry = sum / 10;
            tail = curr;
            curr = curr->next;
        }

        // ✅ append carry at END (most significant digit)
        if (carry) {
            tail->next = new ListNode(carry);
        }

        return reverse(head);
    }
};


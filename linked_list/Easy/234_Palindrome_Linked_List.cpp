class Solution {//TC O(N) and SC->O(1)
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle (slow will point to mid)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;

        // Step 3: Compare first and second halves
        ListNode* check = secondHalf;
        bool isPalin = true;
        while (check) {
            if (firstHalf->val != check->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            check = check->next;
        }

        // Step 4 (optional): Restore the list
        reverseList(secondHalf);

        return isPalin;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // new head
    }
};

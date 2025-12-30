class Solution {
public:
// Time Complexity: O(n)

// Space Complexity: O(1)
   ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;

    ListNode* t1 = new ListNode(0); // odd
    ListNode* t2 = new ListNode(0); // even
    ListNode* tt1 = t1;
    ListNode* tt2 = t2;

    ListNode* temp = head;
    int pos = 1;

    while (temp) {
        if (pos % 2 != 0) {
            tt1->next = temp;
            tt1 = tt1->next;
        } else {
            tt2->next = temp;
            tt2 = tt2->next;
        }
        temp = temp->next;
        pos++;
    }

    tt2->next = NULL;        // VERY IMPORTANT
    tt1->next = t2->next;

    return t1->next;
}

};

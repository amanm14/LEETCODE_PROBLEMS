class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int move=0;
        ListNode*temp=head;
        while(temp!=NULL){
            if(move%2==0&&temp->next!=NULL){
                int z=temp->val;
                temp->val=temp->next->val;
                temp->next->val=z;
            }
            temp=temp->next;
            move++;
        }
        return head;
    }
};

class Solution {
public://O(n) is tc and O(1) is sc
    ListNode* deleteMiddle(ListNode* head) {
        // if(head->next==NULL)
        ListNode*s=head;
        ListNode*f=head;
        ListNode*prev=NULL;
        while(f->next!=NULL&&f->next->next!=NULL){

            prev=s;
            if(s->next) s=s->next;
            if(f->next&&f->next->next)f=f->next->next;
        }
        if(f->next!=NULL){
            prev=s;
            s=s->next;
        }
        if(prev==NULL) return NULL;
        prev->next=s->next;
        return head;
    }
};

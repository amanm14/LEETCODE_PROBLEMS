class Solution {
public:
    // ListNode*clone(ListNode*head){
    //     ListNode*currHead=new ListNode(head->val);
    //     ListNode*currNew=currHead;
    //     ListNode*currOld=head->next;

    //     while(currOld!=NULL){
    //         currNew->next=new ListNode(currOld->val);
    //         currNew=currNew->next;
    //         currOld=currOld->next;
    //     }

        
    //     return currHead;
    // }
    ListNode*reverse(ListNode*node){
        if(node==NULL) return node;

        ListNode*prev=NULL;
        ListNode*curr=node;

        while(curr!=NULL){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
        }
        return prev;
    }
    ListNode*middle(ListNode*slow,ListNode*fast){ //coz of this SC becomes O(N) as it uses recursion call stack although i can make it easily in O(1)
        //TC and SC is O(N) and O(1){ O(n) coz of recursion while finding middle }
        if(slow==NULL||fast==NULL||fast->next==NULL) return slow;

        return middle(slow->next,fast->next->next);
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

    ListNode* copy = middle(head,head);
    ListNode* tt=reverse(copy->next);
    copy->next=NULL;
    // ListNode* rev = reverse(copy);

    ListNode* p1 = head;
    ListNode* p2 = tt;

    while (p1 && p2) {
        ListNode* n1 = p1->next;
        ListNode* n2 = p2->next;

        p1->next = p2;
        p2->next = n1;

        p1 = n1;
        p2 = n2;
    }
        return;
    }
};

class Solution {
public://tc is O(N+M) sc is O(1) we can also solve this using stack without using reverse function which ultimately insrease sc to O(N)
ListNode*reverse(ListNode*l){
    if(l==NULL)
    {
        return NULL;
    }
    ListNode*prev=NULL;
    while(l!=NULL)
    {
        ListNode*temp=l;
        l=l->next;
        temp->next=prev;
        prev=temp;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ll1=reverse(l1);
        ListNode*ll2=reverse(l2);
        ListNode*ans=new ListNode();
        ListNode*ans1=ans;
        int carry=0;
        // while(ll1){
        //     cout<<ll1->val<<" ";
        //     ll1=ll1->next;
        // }
        // cout<<endl;
        // while(ll2){
        //     cout<<ll2->val<<" ";
        //     ll2=ll2->next;
        // }
        while(ll1&&ll2){
            int x=ll1->val;
            int y=ll2->val;
            int z=x+y+carry;
            if(z>9){
                
                ListNode*n1=new ListNode(z%10);
                ans->next=n1;
                ans=ans->next;
                carry=z/10;
            }
            else{
                ListNode*n1=new ListNode(z%10);
                ans->next=n1;
                ans=ans->next;
                carry=z/10;
            }
            ll1=ll1->next;
            ll2=ll2->next;
        }
        // ans->next=NULL;
        while(ll1){
            int x=ll1->val+carry;
            int z=x;
            if(z>9){
                
                ListNode*n1=new ListNode(z%10);

                ans->next=n1;
                ans=ans->next;
                
            }
            else{
                ListNode*n1=new ListNode(z%10);
                ans->next=n1;
                ans=ans->next;
            }
            carry=z/10;
            ll1=ll1->next;
        }
        while(ll2){

            int y=ll2->val+carry;
            int z=y;

            if(z>9){
                
                
                

                ListNode*n1=new ListNode(z%10);

                
                ans->next=n1;
                ans=ans->next;
                
            }
            else{
                ListNode*n1=new ListNode(z%10);
                ans->next=n1;
                ans=ans->next;
            }
            carry=z/10;
            ll2=ll2->next;
        }
        if(carry>0) ans->next=new ListNode(carry);
        return reverse(ans1->next);
    }
};

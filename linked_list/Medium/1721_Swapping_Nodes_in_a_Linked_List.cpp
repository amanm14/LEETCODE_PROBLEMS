class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp=head;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        int l=size-k;
        cout<<l<<" l"<<endl;
        // if(l<k) return head;
        int i=0;
        temp=head;
        ListNode*temp2=head;
        
        
        
        while(i<l){
            
            if(temp)temp=temp->next;
            else temp=head;
            i++;
        }
        i=0; 
        while(i<k-1){
            if(temp2->next)temp2=temp2->next;
            else temp2=head;
            // cout<<"i->"<<i<<endl;
            i++;
        }
        int z=temp->val;
        temp->val=temp2->val;
        temp2->val=z;
        return head;
    }
};

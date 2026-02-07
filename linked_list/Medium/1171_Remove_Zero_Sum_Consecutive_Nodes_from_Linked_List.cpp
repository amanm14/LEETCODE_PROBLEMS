class Solution {
public://O(N3) is tc and O(n) is sc
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*n=head;
        int size=0;

        while(n!=NULL)
        {
            n=n->next;
            size++;
        }
        n=head;
        int i=0;
        int arr[size];
        while(n!=NULL)
        {
            arr[i++]=n->val;
            n=n->next;
        }
        for(int i=0;i<size;i++)
        {
            int sum=arr[i];
            for(int j=i+1;j<size;j++)
            {
                sum+=arr[j];
                if(sum==0)
                {
                    // int j=i-1;
                    int i1=i;
                    while(i1<=j){
                    
                    arr[i1]=0;
                    i1++;
                    }
                }
            }
            
        }
        ListNode*nn=new ListNode();
        head=nn;
        for(int i=0;i<size;i++)
        {
            if(arr[i]!=0){
                ListNode*n1=new ListNode(arr[i]);
                nn->next=n1;
                nn=nn->next;
            }
        }
        return head->next;
    }
};

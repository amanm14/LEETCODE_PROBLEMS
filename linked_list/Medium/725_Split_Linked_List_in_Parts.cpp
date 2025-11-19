class Solution {
public://TC O(n+k) k is the iteration we are performing and SC O(N)
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k,nullptr);
        ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        
        int check=cnt/k;
        int extra=cnt%k;

        ListNode*temp1=head;

        for(int i=0;i<k;i++){
            if(!temp1){
                ans[i]=NULL;
                continue;
            }

            ans[i]=temp1;
            int extrapart=check+(extra>0?1:0);
            if(extra>0) extra--;

            for(int j=1;j<extrapart;j++){
                temp1=temp1->next;
            }
            
            if (temp1) {
            ListNode*nextpart=temp1->next;
            temp1->next=NULL;
            temp1=nextpart;
            }
            
        }
        return ans;
    }
};

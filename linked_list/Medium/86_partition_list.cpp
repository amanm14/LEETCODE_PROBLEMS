class Solution {
public: //O(N) tc and sc we can solve this in O(1) space complexity by taking two dummy list nodes and adding nodes, maintaining order with the condition of small and large
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode*temp=head;
        vector<int>ans;
        vector<int>ans2;
        while(temp!=NULL)
        {
            if(temp->val>=x)
            {
                ans.push_back(temp->val);
            }
            else
            {
                ans2.push_back(temp->val);
            }
            temp=temp->next;
        }
        ListNode*head2=new ListNode();
        ListNode*h=head2;
        for(int i=0;i<ans2.size();i++)
        {
            ListNode*a=new ListNode(ans2[i]);
            head2->next=a;
            head2=head2->next;
        }
        for(int i=0;i<ans.size();i++)
        {
            ListNode*b=new ListNode(ans[i]);
            head2->next=b;
            head2=head2->next;
        }
        head2->next=NULL;
        return h->next;

    }
};

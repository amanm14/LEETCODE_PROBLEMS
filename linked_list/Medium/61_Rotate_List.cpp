class Solution {
public://O(N) SC and TC we can make it in O(1) sc and write more efficient solution
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int>temp;
        // vector<int>ans;
        ListNode*t=head;
        while(t!=NULL){
            temp.push_back(t->val);
            t=t->next;
        }
         int n = temp.size();
         if(n==0) return NULL;
        k = k % n;
        if (k == 0) return head;

    // CORRECT ROTATION INDEX
        int j = n - k;   // <-- this is the correct index where rotation starts

        vector<int> ans;

    // push rotated elements
    for (int i = j; i < n; i++) ans.push_back(temp[i]);
    for (int i = 0; i < j; i++) ans.push_back(temp[i]);

        ListNode*aa=new ListNode();
        ListNode*kk=aa;
        for(int i=0;i<ans.size();i++)
        {
            ListNode*jj=new ListNode(ans[i]);
            aa->next=jj;
            aa=aa->next;
        }
        return kk->next;
    }
};

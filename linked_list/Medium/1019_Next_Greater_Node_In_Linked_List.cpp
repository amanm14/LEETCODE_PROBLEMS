class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        ListNode*h=head;
        while(h!=NULL)
        {
            ListNode*t=h->next;
            while(t!=NULL&&t->val<=h->val){
                t=t->next;
            }
            if(t) ans.push_back(t->val);
            else ans.push_back(0);
            h=h->next;
        }
        return ans;
    }
};

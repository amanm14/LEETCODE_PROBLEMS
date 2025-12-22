class Solution {
public:// tc is O(NlogN) adn sc is O(N) bu we can solve it using merge sorrt in O(NLogn) and O(logn)
    ListNode* sortList(ListNode* head) {
         vector<int>ans;
         ListNode*h=head;
         while(head){
            ans.push_back(head->val);
            head=head->next;
         }
         sort(ans.begin(),ans.end());
         ListNode*a=new ListNode();
         ListNode*b=a;
         for(int i=0;i<ans.size();i++){
            ListNode*temp=new ListNode(ans[i]);
            ListNode*temp2=new ListNode();
            a->next=temp;
            a=a->next;
         }
         return b->next;
    }
};

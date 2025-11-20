class Solution {
public:
    // TC ->O(N+M) SC->O(M) m is element in nums
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        
        ListNode dummy(-1);// stack will get used whic is fast and automatic memory release
        dummy.next=head;
        ListNode*curr=head;
        ListNode*prev=&dummy;
    // In linkedlist what happen like if take reference of osme node 1 =2 when you update 2 then 1 will not  get updated autoatically if you are updatin 2 you have to update 1 too 

        bool flag=true,removed=false;
        while(curr!=NULL)
        {
            int z=curr->val;
            if(st.count(z)){
                prev->next=curr->next;
                // delete curr;
                curr=prev->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return dummy.next;
    }
};

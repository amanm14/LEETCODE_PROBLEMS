/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include<random>
class Solution {
public://O(N) is tc and O(1) is sc
    ListNode*temp=new ListNode();
    
    Solution(ListNode* head) {
        temp=head;
    }
    
    int getRandom() {
       int res, length=1;
       ListNode* x= temp;
       while(x){
            if(rand()%length==0) res=x->val;
            length++;
            x=x->next;
       }
       return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

 /*
 CALLS:

remove(5)
 └ remove(3)
    └ remove(2)
       └ remove(10)
          └ remove(6)
             └ remove(8)
                └ remove(1) → returns 1

RETURNS:

remove(8): next=1, 1>8?no → return 8→1
remove(6): next=8, 8>6?yes → return 8→1
remove(10): next=8, 8>10?no → return 10→8→1
remove(2): next=10, 10>2?yes → return 10→8→1
remove(3): next=10, 10>3?yes → return 10→8→1
remove(5): next=10, 10>5?yes → return 10→8→1

 */
class Solution {//TCO(N) nd SC O(N)
public:
    ListNode* removeNodes(ListNode* head) {
       if(!head||!head->next){
        return head;
       }
       ListNode*nextfilter=removeNodes(head->next);
       if(nextfilter->val>head->val){
            return nextfilter;
       }
       head->next=nextfilter;
       return head;
    }
};

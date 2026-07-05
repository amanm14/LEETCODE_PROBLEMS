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
class Solution {
public://O(n) is tc and O(1) is sc
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            if(curr->next!=NULL&&curr->val==curr->next->val){
                while(curr->next!=NULL&&curr->val==curr->next->val){
                    curr=curr->next;
                }
                prev->next=curr->next;
            }
            else{
                prev=curr;
            }
            curr=curr->next;
        }
        return dummy->next;

        // if(head==NULL) return head;
        // ListNode*p=head;
        // ListNode*s;
        // cout<<"11 "<<endl;
        // if(head->next) s=head->next;
        // else{
        //      return head;
        // }
        // cout<<"12 "<<endl;
        // ListNode*f;
        // if(head->next&&head->next->next) f=head->next->next;
        // else{
            
        //     if(head->val==head->next->val){
        //         return NULL;
        //     }
        // }
        // cout<<"13 "<<endl;
        // bool ch=false;
        // while(p!=NULL&&s!=NULL&&f!=NULL)
        // {
            
        //     if(p->val==f->val){
        //         if(f->next) p=f->next;
        //         if(f->next&&f->next->next)s=f->next->next;
        //         if(s->next) f=s->next;
        //         if(ch==false){
        //             if(p->val!=f->val) ch=true;
        //             head=p;
        //         }
        //         cout<<"1 "<<endl;
        //         // if(f->next) p->next=f->next;
        //         // s=f->next;
        //         // if(f->next&&f->next->next) f=f->next->next;
        //     }
        //     else if(p->val==s->val){
        //         cout<<"2 "<<endl;
        //         p=f;
        //         s=f->next;
        //         if(f->next->next) f=f->next->next;

        //         // p->next=f;
        //         // s=f;
        //         // f=f->next;
        //     }
        //     else if(s->val==f->val){
        //         cout<<"3 "<<endl;
               
        //         p->next=f->next;
        //         if(f->next)s=f->next;
        //         if(f->next&&f->next->next)f=f->next->next;
                

        //     }
        //     else{
        //         cout<<"4 "<<endl;
        //         p=s;
        //         s=f;
        //         f=f->next;
        //     }

        // }
        // return head;
        // tt->next=head;
        // while(head!=NULL&&head->next!=NULL&&head->val==head->next->val)
        // {
        //     head=head->next;
        // }
        // head=head->next;
        // ListNode*temp=head;
        // while(temp!=NULL&&temp->next!=NULL)
        // {
        //     if(temp->val!=temp->next->val)
        //     {
                
        //         if(temp->next->next!=NULL&&temp->next->val==temp->next->next->val)
        //         {
                    
        //             tt=temp;
                    
        //         }
        //         temp=temp->next;
        //     }
        //     else{
        //         temp=temp->next;
        //         tt->next=temp->next;
        //     }
            
            
        // }
        // return head;
    }
};

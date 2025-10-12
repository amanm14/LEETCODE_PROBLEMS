/* Initially, I was storing true and false in ans and then updating it according to a and b, which made it two steps, which broke the logic. Then, I made the comparison of a and b and ans together, then returned the value which makes the logic good  */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL){
            return true;
        }
        if(p!=NULL&&q==NULL||p==NULL&&q!=NULL){
            return false;
        } 
        bool ans=false;
        if(p->val==q->val) ans= true;
        bool a=isSameTree(p->left,q->left);//false
        bool b=isSameTree(p->right,q->right);//false
        return a&&b&&ans;
    }
};

//It uses the concept of Morris traversal to flatten it 
// The only advantage of Morris traversal is that it takes O(1) space over other traversals where as TC is O(n) it visisted each nodes 3 times

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode*curr=root;
        while(curr!=NULL){
            TreeNode*prev=curr;
            if(curr->left){
                prev=curr->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;// Here we are adding NULL to the left of the each node as required in the question
            }
            curr=curr->right;
        }
        return;
    }
};

class Solution {
//It's a tricky question because in this qus we have to only traverse to the left og the tree which we can do that by checking two steps of left and left right which i dont know coz of that I found it difficult to solve 
//Initially, I was struggling to understand how we check if leaf is left leaf 
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // if(root->left==NULL&&root->right==NULL){
        //     return root->val;
        // }
        if(root==NULL) return 0;
        int ans=0;
        if(root->left&&root->left->left==NULL&&root->left->right==NULL){
            ans+=root->left->val;
        }
        ans+=sumOfLeftLeaves(root->left);
        ans+=sumOfLeftLeaves(root->right);
        return ans;
    }
};

class Solution {
public://O(n) and O(H)
    void solve(TreeNode*root,int&ans)
    {
        if(root==NULL){
            return;
        }
        if(root->val%2==0){
            if(root->left&&root->left->left){
                ans+=root->left->left->val;
            }
            if(root->right&&root->right->right){
                ans+=root->right->right->val;
            }
            if(root->right&&root->right->left){
                ans+=root->right->left->val;
            }
            if(root->left&&root->left->right){
                ans+=root->left->right->val;
            }
        }
        solve(root->left,ans);
        solve(root->right,ans);
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};

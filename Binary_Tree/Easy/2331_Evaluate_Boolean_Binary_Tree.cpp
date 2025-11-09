class Solution {//TC nd SC -> O(N) nd O(H)->O(N) WC skewed tree
public:
    bool evaluateTree(TreeNode* root) {
        if(!root->left&&!root->right){
            return root->val;
        }
        bool a=evaluateTree(root->left);
        bool b=evaluateTree(root->right);
        bool ans;
        if(root->val==3) ans=  a&&b;
        else ans =a||b;
        return ans;
    }
};

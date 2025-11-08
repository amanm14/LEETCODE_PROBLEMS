class Solution {//tc nd sc -> O(N)
public:
void solve(TreeNode*root,vector<int>&z){
    if(root==NULL) return;
    solve(root->left,z);
    z.push_back(root->val);
    solve(root->right,z);
    return ;
}
    bool isValidBST(TreeNode* root) {
        vector<int>z;
        solve(root,z);
        for(int i=1;i<z.size();i++){
            if(z[i-1]>=z[i]){
                return false;
            }
        }
        return true;
    }
};

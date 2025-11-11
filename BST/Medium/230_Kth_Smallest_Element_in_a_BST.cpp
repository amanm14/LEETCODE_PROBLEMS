class Solution {
    // we hacve to maintain size function in treenode and first we have to run a function which check if size is same or not 
    // if not if size became greater or less we call fuctnion accordingly on right or left and when k==size we return root-> val
    // this approach is for the conditon in which tree keeps adding removing elelemnt 
public:
    void solve(TreeNode* &root,vector<int>&ans){
        if(root==NULL) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL||k<1) return 0;
        vector<int>ans;
        solve(root,ans);
        return ans[k-1];
    }
};

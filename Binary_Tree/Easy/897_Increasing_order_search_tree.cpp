class Solution {
public:
    // void solve(TreeNode* root, vector<int>& ans) {
    //     if (!root) return;
    //     solve(root->left, ans);
    //     ans.push_back(root->val);
    //     solve(root->right, ans);
    // }

    // TreeNode* increasingBST(TreeNode* root) {
    //     vector<int> ans;
    //     solve(root, ans);

    //     TreeNode* dummy = new TreeNode(-1); // dummy node
    //     TreeNode* curr = dummy;

    //     for (int i = 0; i < ans.size(); i++) {
    //         curr->right = new TreeNode(ans[i]);
    //         curr = curr->right;
    //     }

    //     return dummy->right; // new root
    // } //O(N) nd SC O(n)
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return ;
        TreeNode*dummy=new TreeNode(-1);
        TreeNode*curr=dummy;
        solve(root,curr);
        return dummy->right;
    }
    void solve(TreeNode*root,TreeNode*&curr){ //O(N) nd space we are not using exrtra vector only O(H) stack call of recursion
        if(!root) return NULL;
        solve(root->left,curr);
        root->left=NULL;
        curr->right=root;
        curr=root;
        solve(root->right,curr);
        return ;
    }
    
};

class BSTIterator {//O(n) O(n)
public:

    vector<int>ans;
    int idx=0;
    void solve(TreeNode*root){
        if(root==NULL) return;
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        if(ans.size()<idx) return -1;
        else return ans[idx++];
    }
    
    bool hasNext() {
        if((idx+1)>ans.size()) return false;
        else return true;
    }
};

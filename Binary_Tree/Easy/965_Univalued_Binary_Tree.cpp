class Solution {
public:
    bool check(TreeNode*root,int val){
        if(root==NULL) return true;
        if(root->val!=val) return false;
        
        bool x=check(root->left,val);
        bool y=check(root->right,val);
        if(x==false||y==false) return false;
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        int val=root->val;
        bool z=check(root,val);
        return z;
    }
};

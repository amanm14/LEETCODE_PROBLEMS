class Solution {
public:
    int ans=INT_MAX;
    TreeNode*prev=NULL;
    int minDiffInBST(TreeNode* root) {//TC 0> O(N) SC ->O(H)
        // if(root==NULL) return 0;
        // if(root->left==NULL&&root->right==NULL) return root->val;
        // // int z=root->val;
        // int x=minDiffInBST(root->left); // This might return minimum diffeence not nodes value thats where your logic goes wrong 
        // ans=min(ans,(root->val-x));
        // int y=minDiffInBST(root->right);
        // ans=min(ans,(y-root->val));
        // return ans;
    if(root==NULL) return 0;
    minDiffInBST(root->left);
    if(prev!=NULL){
        ans=min(ans,root->val-prev->val);
    }
    prev=root;
    minDiffInBST(root->right);
    return ans;
        
    }
};

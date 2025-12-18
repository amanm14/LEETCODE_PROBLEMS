class Solution {
public: //O(N) and O(H) tc and sc
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;

        root->right=convertBST(root->right);//coz we need to calculate only those values which are greater than curr root val as property of bst right element is greater

        sum+=root->val;
        root->val=sum;
        root->left=convertBST(root->left);
        
        return root;
    }
};

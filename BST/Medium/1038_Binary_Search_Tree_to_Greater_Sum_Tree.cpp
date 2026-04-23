/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int x=0;
    // int sum(TreeNode*root)
    // {
    //     if(root==NULL)
    //     {
    //         return 0;
    //     }
    //     return root->val+sum(root->left)+sum(root->right);
        
    // }

    //O(n) and O(k) k is recusrsion space
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        
        bstToGst(root->right);
        x=x+(root->val);
        root->val=x;
        bstToGst(root->left);

        return root;
    }
};

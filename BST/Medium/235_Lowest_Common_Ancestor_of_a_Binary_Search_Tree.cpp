/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public://O(n) is tc and O(k) is space to call recursion
    TreeNode*solve(TreeNode*root,int p,int q)
    {
        if(root==NULL) return root;
        if(root->val>max(p,q)){
            return solve(root->left,p,q);
        }
        
        if(root->val<min(p,q)){
            return solve(root->right,p,q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int p1=p->val;
        int q1=q->val;
        int m=min(p1,q1);
        return solve(root,p1,q1);
        
    }
};

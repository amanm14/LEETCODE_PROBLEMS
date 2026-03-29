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
//Please upvote if it helps :)
class Solution 
{
public://O(N) is tc and O(N) is sc
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(!root) return root;
        
        queue<TreeNode*> q;
        vector<int> values;
        q.push(root);
        int level=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            for(int i=0; i<sz; i++)
            {
                
                TreeNode* node = q.front(); q.pop();
                
                if(level%2)
                    // cout<<node->val<<endl;
                    node->val = values[sz-i-1];
                    // cout<<node->val<<endl;
                
                if(node->left)
                {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right) 
                {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
                
            }
            values = temp;
            level++;
        }
        return root;
            
        
    }
};
// class Solution {
// private:
//     void reverse(TreeNode* rootL, TreeNode* rootR, int level) {
//         if(rootL == NULL and rootR == NULL) return;
//         if(level % 2 == 0) swap(rootL->val, rootR->val);
//         reverse(rootL->left, rootR->right, level + 1);
//         reverse(rootL->right, rootR->left, level + 1);
//     }
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         reverse(root->left, root->right, 0);
//         return root;
//     }
// };

class Solution {
public://O(N) is tc and sc 
    TreeNode* solve(TreeNode* root, unordered_set<int>& del, vector<TreeNode*>& ans) {
        if (!root) return NULL;

        root->left = solve(root->left, del, ans);
        root->right = solve(root->right, del, ans);

        if (del.count(root->val)) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            return NULL;   // delete this node
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;

        root = solve(root, del, ans);
        if (root) ans.push_back(root);

        return ans;
    }
};

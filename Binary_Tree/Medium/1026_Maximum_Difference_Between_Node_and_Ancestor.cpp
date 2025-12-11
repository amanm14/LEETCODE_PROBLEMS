class Solution {
public://O(N) is TC and SC is O(H)
    int dfs(TreeNode* root, int mx, int mn) {
        if (!root) return mx - mn;

        mx = max(mx, root->val);
        mn = min(mn, root->val);

        int left = dfs(root->left, mx, mn);
        int right = dfs(root->right, mx, mn);

        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};

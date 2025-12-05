class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            while (sz--) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);
        }

        int last = ans.size() - 1;
        int sum = 0;
        for (int val : ans[last]) sum += val;

        return sum;
    }
};
// ⏳ Complexity
// Time Complexity: O(n)

// Space Complexity: O(n) (queue + storing levels)

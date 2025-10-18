class Solution { //TC O(N) SC O(W) width of the level that we store in queue
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int lvl = q.size();
            double val = 0; // reset for each level

            for (int i = 0; i < lvl; i++) {
                TreeNode* temp = q.front();
                q.pop();

                val += temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            ans.push_back(val / lvl);
        }

        return ans;
    }
};

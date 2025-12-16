class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;

        while (!q.empty()) {
            int size = q.size();  // number of nodes at this level
            ans = q.front()->val; // first node of this level

            while (size--) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};

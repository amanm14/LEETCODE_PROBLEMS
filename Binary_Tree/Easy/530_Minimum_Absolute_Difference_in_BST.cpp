class Solution {
public:
    int minDiff = INT_MAX;
    int prev = -1;
O(n) TC and SC is O(H)
    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != -1) {
            minDiff = min(minDiff, abs(root->val - prev));
        }
        prev = root->val;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return -1;

        int leftVal = root->left->val;
        int rightVal = root->right->val;

        // If left child equals root, recurse deeper
        if (leftVal == root->val)
            leftVal = findSecondMinimumValue(root->left);

        // If right child equals root, recurse deeper
        if (rightVal == root->val)
            rightVal = findSecondMinimumValue(root->right);

        // Now combine results
        if (leftVal != -1 && rightVal != -1)
            return min(leftVal, rightVal);
        else if (leftVal != -1)
            return leftVal;
        else
            return rightVal;
    }
};

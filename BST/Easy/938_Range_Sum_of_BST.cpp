class Solution { //TC and SC are O(N) nd O(H)
public:
    // int ans=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr)
        return 0;

    // Case 1: Node value is within range
    if (root->val >= low && root->val <= high) {
        return root->val
             + rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }

    // Case 2: Node value is smaller than low → skip left subtree
    else if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }

    // Case 3: Node value is greater than high → skip right subtree
    else { // root->val > high
        return rangeSumBST(root->left, low, high);
    }
}

};

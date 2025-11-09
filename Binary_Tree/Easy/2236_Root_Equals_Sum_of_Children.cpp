class Solution {// TC nd SC ->O(1) nd O(1)
public:
    bool checkTree(TreeNode* root) {
        return root->left->val+root->right->val==root->val?true:false;
    }
};

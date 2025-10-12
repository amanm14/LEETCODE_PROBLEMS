/*
why not +1 in both left right calling
Step 1 — at node 1

a = 1 + countNodes(2)

b = 1 + countNodes(3)

Step 2 — left subtree (node 2)

a = 1 + countNodes(NULL) → 1

b = 1 + countNodes(NULL) → 1

returns a + b = 2 
(should be 1, but you added +1 twice)*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int a=1+countNodes(root->left)+countNodes(root->right);
        return a;
    }
};

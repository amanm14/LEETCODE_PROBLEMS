class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        // if(root->left||!root->right&&!root->left||root->right) return root; //accesing roots left and right is safe as long as root exist even if left or right is null
      //if the root is not changing, we return root if root might need to be changed to perform the operations we return function with updated pararmeter 
      TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;
        invertTree(root->left); 
        invertTree(root->right);
        return root;
    }
};

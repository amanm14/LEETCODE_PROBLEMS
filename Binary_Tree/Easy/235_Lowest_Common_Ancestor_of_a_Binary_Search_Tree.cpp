class Solution {
public:
    // TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //     TreeNode*root=new TreeNode();
    //     if(root1==NULL&&root2==NULL){
    //         return NULL;
    //     }
    //     if(root1!=NULL&&root2==NULL){
    //         root->val=root1->val;//here we have problem when lets say root2 is null and program will reach mergeTrees(root1->left,root2->left); where you willl call NULLs->left which will give us NULL pointer error
    //     }
    //     if(root1==NULL&&root2!=NULL){
    //         root->val=root2->val;
    //     }
    //     if(root1!=NULL&&root2!=NULL){
    //        int z=root1->val+root2->val;
    //        root->val=z;
    //     }
    //     root->left=mergeTrees(root1->left,root2->left);
    //     root->right=mergeTrees(root1->right,root2->right);
    //     return root;
    // }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1==NULL&&root2==NULL){
            return NULL;
        }
        if(root2==NULL){
            return root1;
        }
        if(root1==NULL){
           return root2;
        }
        int z=root1->val+root2->val;
        TreeNode*root=new TreeNode(z);
        root->left=mergeTrees(root1->left,root2->left);
        root->right=mergeTrees(root1->right,root2->right);
        return root;
    }
};

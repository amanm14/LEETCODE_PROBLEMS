class Solution {
public:
    // bool isSubtree(TreeNode* root, TreeNode* subRoot) {//this consider given tree is bst thats why this solution is wrong
    //     if(root==NULL&&subRoot==NULL) return true;
    //     if(subRoot==NULL&&root!=NULL||subRoot!=NULL&&root==NULL) return false;
    //     if(root->left&&subRoot->val==root->left->val){
    //         return isSubtree(root->left,subRoot);
    //     }
    //     if(root->val==subRoot->val){
    //         bool x= isSubtree(root->left,subRoot->left);
    //         bool y= isSubtree(root->right,subRoot->right);
    //         if(x==true&&y==true) return true;
    //         else return false;
    //     }
        
    //     if(root->val<subRoot->val) return isSubtree(root->left,subRoot);
    //     else return isSubtree(root->right,subRoot);
    // }
    // class Solution {
// public:
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
// };

};

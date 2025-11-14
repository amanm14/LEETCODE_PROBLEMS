class Solution { // TC O(n) and sc O(n)
public:
    int i=0;//Use a global / reference index so the preorder array is scanned only once.
    TreeNode* construct(vector<int>preorder,int lower,int upper){
        // if(root==NULL) return NULL;
        if(i==preorder.size()){
            return NULL;
        }
        if(preorder[i]<lower||preorder[i]>upper){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[i]);
        i++;
        root->left=construct(preorder,lower,root->val);
        root->right=construct(preorder,root->val,upper);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder,INT_MIN,INT_MAX);
    }
};
// class Solution { // tc O(n2) sc O(n)
// public:
//     TreeNode* insertNode (TreeNode* node, int val) {
//         if (node == nullptr) return new TreeNode(val);
//         // cout<<node->val<<" "<<val<<endl;
//         if (node->val > val) {
//             node->left = insertNode(node->left, val);
//         } else {
//             node->right = insertNode(node->right, val);
//         }
//         return node;
//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode* root = nullptr;
//         for(auto& it : preorder) {
//             root = insertNode(root, it);
//             // cout<<endl;
//         }
//         return root;
//     }
// };

class Solution {
    // O(n2) TC we can increase this by calling recursion and suming in same function
    // O(n) SC considering the stack pf recursion
// public:
//     int solve(TreeNode*l){
//         if(!l) return 0; 
//         int x=l->val+solve(l->left)+solve(l->right);
//         return x;
//     }
//     int ans=0;
//     int findTilt(TreeNode* root) {
//         if(root==NULL) return 0;
//         findTilt(root->left);
//         findTilt(root->right);
//         int ans1=solve(root->left);
//         int ans2=solve(root->right);
//         cout<<"Check"<<abs(ans2-ans1)<<endl;
        
//         ans+=abs(ans2-ans1);
//         return ans;

//     }
public:
    int solve(TreeNode*root,int&ans){
        if(!root) return 0; 
        int ans1=solve(root->left,ans);
        int ans2=solve(root->right,ans);
        ans+=abs(ans2-ans1);
        return ans1+ans2+root->val;
    }
    int ans=0;
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
         solve(root,ans);
        return ans;

    }
};

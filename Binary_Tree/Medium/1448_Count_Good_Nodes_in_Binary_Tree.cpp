// class Solution {
// public:
//     int solve(TreeNode*root,int cnt,int&ans,map<int,int>mp,bool flag,int m)
//     {
//         if(root==NULL){
//             return ans;
//         }
        
//         if(root->val>=cnt){
//             if(!mp.contains(root->val))ans++;
            
//             if(root->val==cnt&&flag==true&&m<=root->val) ans++;
//             else if(mp.contains(root->val)&&root->val==m) ans++;
//             // cout<<"hello"<<" ";
//         }
//         cout<<ans<<" ans ";
//         cout<<endl;
//         m=max(m,root->val);
//         flag=true;
//         mp[root->val]++;
//         solve(root->left,cnt,ans,mp,flag,m);
//         solve(root->right,cnt,ans,mp,flag,m);
//         return ans;
//     }
//     int goodNodes(TreeNode* root)
//     {
//         if(root==NULL){
//             return 0;
//         }
//         int cnt=root->val;
//         map<int,int>mp;
//         int ans=0;
//         bool flag=false;
//         int m=root->val;
//         solve(root,cnt,ans,mp,flag,m);
//         return ans;
//     }
// };

class Solution {
public://O(N) ius tc and O(H) is sc
    int dfs(TreeNode* root, int maxSoFar) {
        if (root == NULL) return 0;

        int good = 0;
        if (root->val >= maxSoFar) {
            good = 1;
            maxSoFar = root->val;
        }

        good += dfs(root->left, maxSoFar);
        good += dfs(root->right, maxSoFar);

        return good;
    }

    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return dfs(root, root->val);
    }
};

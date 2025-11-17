class Solution {
public:
// TC O(N) sc is O(N)
// vector<int>temp if i pass it withpout reference it will cost one more (N) so our tc will become O(N2) coz we have t copy temp in each recursion call
    void solve(TreeNode*root,int target, vector<vector<int>>&ans,int z,vector<int>&temp)
    {
        if(root==NULL){
            return;
        }
        
        temp.push_back(root->val);
        z=z+root->val;

        solve(root->left,target,ans,z,temp);
        solve(root->right,target,ans,z,temp);

        if(z==target&&root->left==NULL&&root->right==NULL){
            ans.push_back(temp);
        }
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
         solve(root,targetSum,ans,0,temp);
         return ans;
    }
};

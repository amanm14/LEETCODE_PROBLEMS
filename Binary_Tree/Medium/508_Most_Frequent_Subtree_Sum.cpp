class Solution {
public://O(N) is time and space complexity
    map<int,int>mp;
    vector<int>ans;
    int h=INT_MIN;
    int solve(TreeNode*root){
        if(root==NULL) return 0;

        int x=solve(root->left);
        int y=solve(root->right);
        
        int z=root->val+x+y;
        mp[z]++;
        return z;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==NULL) return ans;
        solve(root);
        for(auto i:mp){
            if(i.second==h){
                ans.push_back(i.first);
            } 
            if(i.second>h){
                h=i.second;
                ans.clear();
                ans.push_back(i.first);
            }
            
        }
        // mp[sum]++;
        // ans.push_back(sum);

        // findFrequentTreeSum(root->left);
        // findFrequentTreeSum(root->right);
        
        return ans;
    }
};

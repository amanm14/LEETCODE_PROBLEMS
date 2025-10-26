class Solution {
public:
    
    void solve(TreeNode*root,vector<int>&ans1)
    {
        if(root==NULL){
            return ;
        }
        if(!root->left&&!root->right){
            ans1.push_back(root->val);
        } 

        solve(root->left,ans1);
        solve(root->right,ans1);

        return ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) { //TC->O(N+N) SC->O(N+N) can be improved to H if we use stack to solve it
        if(!root1&&root2||root1&&!root2) return false;
        vector<int>ans1;
        vector<int>ans2;

        solve(root1,ans1);
        solve(root2,ans2);

        if(ans1.size()!=ans2.size()) return false;
        int i=0;
        // cout<<ans1.size()<<" ans1 "<<ans2.size()<<" ans2 "<<endl;
        while(i<ans1.size()&&i<ans2.size()){
            // cout<<ans1[i]<<" ans1 "<<ans2[i]<<" ans2 "<<endl;
            if(ans1[i]!=ans2[i]){
                return false;
            }
            i++;
        }
        

        return true;
    }
};

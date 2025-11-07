class Solution { //TC -> O(N*H) and SC->O(H)
public:
    int bTon(string z){
        int j=0,ans=0;
        for(int i=z.length()-1;i>=0;i--)
        {
            int k=z[i];
            ans=ans+k*pow(2,j++);
        }
        return ans;
    }
    void solve(TreeNode*root,string k,vector<string>&a){
        if(root==NULL){
            return ;
        }
        char z=root->val;
        k=k+z;
        solve(root->left,k,a);
        solve(root->right,k,a);
        if(root->left==NULL&&root->right==NULL){
            a.push_back(k);
            k="";
        }
        return ;
    }
    int sumRootToLeaf(TreeNode* root) {
          string k="";
          vector<string>a;
          solve(root,k,a);
          int ans=0;
          for(int i=0;i<a.size();i++){
            ans=ans+bTon(a[i]);
          }
          return ans;
    }
};

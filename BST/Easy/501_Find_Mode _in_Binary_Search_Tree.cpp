class Solution {// TC O(N) SC-> O(H)
public:
    int m=0;
    int count=0;
    vector<int>ans;
TreeNode*prev=NULL;
    vector<int> findMode(TreeNode* root) {
        
        if(root==NULL) return ans;
        findMode(root->left);
        
        if(prev&&prev->val==root->val){
            count++;
        }
        else count=1;
        // cout<<value<<" val "<<count<<" "<<m<<" "<<endl;
        if(count>m){
            ans.clear();
            ans.push_back(root->val);
            // cout<<ans[0];
            m=count;
        }
        else if(count==m){//m!=0&&count!=0&&
            ans.push_back(root->val);
        }
        prev=root;
        findMode(root->right);
        return ans;
    }
};

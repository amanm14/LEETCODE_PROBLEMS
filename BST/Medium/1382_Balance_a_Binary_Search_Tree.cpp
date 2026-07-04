/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public://O(n) is and tc

    TreeNode* dfs(vector<int>& ans, int l, int r)
{
    if(l > r)
        return NULL;

    int mid = (l+r)/2;

    TreeNode* root = new TreeNode(ans[mid]);

    root->left = dfs(ans, l, mid-1);

    root->right = dfs(ans, mid+1, r);

    return root;
}
    // void dfs(TreeNode*root,vector<int>&ans,int i,int n,TreeNode*aa)
    // {//you are traversing the tree but you have to traverse ans array instead
    //     if(root==NULL) return;
    //     int m=(i+n)/2;
    //     TreeNode*t=new TreeNode(ans[m]);
    //    if(aa==NULL){
    //     aa=t;
    //    }
    //    else{
    //         if(aa->val>ans[m]){
    //             aa->left=t;
    //             aa=t; //it is pdating aaa locally aa will not chagne its ointing location
    //         }
    //         else{
    //             aa->right=t;
    //             aa=t;
    //         }
    //    }
    //     dfs(root->left,ans,i,m-1,aa);
    //     dfs(root->right,ans,m,n,aa);
    //     return;
    // }
    void traversal(TreeNode*root,vector<int>&ans)
    {
        if(root==NULL) return;
        traversal(root->left,ans);
        ans.push_back(root->val);
        traversal(root->right,ans);
        return ;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
       traversal(root,ans);
       TreeNode*aa=new TreeNode(ans[(0+ans.size()-1)/2]);
       return dfs(ans,0,ans.size()-1);
        // return aa;
    }
};

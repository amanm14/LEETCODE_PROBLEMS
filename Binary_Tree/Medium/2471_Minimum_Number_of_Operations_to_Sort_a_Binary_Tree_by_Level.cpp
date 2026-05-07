// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void p(TreeNode*root,vector<int>&ans)
//     {
//         if(root==NULL)
//         {
//             return ;
//         }
//         ans.push_back(root->val);
//         p(root->left,ans);
//         p(root->right,ans);
//         return;
//     }
//     int minimumOperations(TreeNode* root) {
//         vector<int>ans;
//         p(root,ans);
//         vector<int>ans2(ans);
//         sort(ans.begin(),ans.end());
//         int cnt=0;
//         for(int i=0;i<ans.size();i++){
//             cout<<ans[i]<<"  "<<ans2[i]<<" ";
//             if(ans[i]!=ans2[i]){
//                 cnt++;
//             }
//         }
//         return cnt/2;

//     }
// };
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
public://O(nlogn) is tc and O(n) is sc
    static int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int swaps=0;
        while(!q.empty()){
            int qz=q.size();
            vector<int> idx(qz, 0);
            iota(idx.begin(), idx.end(), 0);
            vector<int> arr(qz, 0);
            for(int i=0; i<qz; i++){
                auto node=q.front();
                q.pop();
                arr[i]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // each value is unique, no need for stable_sort
            sort(idx.begin(), idx.end(), [&](int i, int j){
                return arr[i]<arr[j];
            });
            for(int i=0; i<qz; ){
                int j=idx[i];
                if (j!=i){// recheck
                    swaps++;
                    swap(idx[i], idx[j]);
                }
                else i++; // next iteration
            }
        }
        return swaps;
    }
};


// auto init = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 'c';
// }();

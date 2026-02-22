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
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
// --------------------------------------------------- Time Complexity: O(n)
// --------------------------------------------------- Space Complexity: O(n)
    //     int lvl=0;
    //     queue<TreeNode*>q;
    //     q.push(root);

    //    map<int,int>mp;
    //     while(!q.empty())
    //     {
    //         int s=q.size();
    //         int sum=0;
    //         int s2=s;
    //         queue<TreeNode*>q2;
            
    //         while(s>0)
    //         {
    //             TreeNode*temp=q.front();
    //             q2.push(temp);
    //             q.pop();

    //             if(temp->left){
    //                 mp[temp->left->val]=temp->val;
    //                  q.push(temp->left);
    //                 //  cout<<mp[temp->left->val]<<" mp[temp->val ";
    //             }
    //             if(temp->right){
    //                 mp[temp->right->val]=temp->val;
    //                 q.push(temp->right);
    //                 // cout<<mp[temp->right->val]<<" mp[temp->val ";
    //             }
    //             sum+=temp->val;
    //             s--;
    //         }
    //     }
    //     // for( auto i:mp){
    //     //     cout<<i.first<<" "<<i.second<<" ";
    //     // }
    //     while (!q.empty()) {
    //             q.pop();
    //         }
    //     q.push(root);
    //     while(!q.empty())
    //     {
    //         int s=q.size();
    //         int sum=0;
    //         int s2=s;
    //         queue<TreeNode*>q2;
    //         // map<int,int>mp;
    //         while(s>0)
    //         {
    //             TreeNode*temp=q.front();
    //             q2.push(temp);
    //             q.pop();

    //             if(temp->left){
    //                 // mp[temp->left->val]=temp->val;
    //                  q.push(temp->left);
    //             }
    //             if(temp->right){
    //                 // mp[temp->right->val]=temp->val;
    //                 q.push(temp->right);
    //             }
    //             sum+=temp->val;
    //             s--;
    //         }
    //         s2=q2.size();
    //         // cout<<" sum "<<sum<<endl;
    //         if(lvl>1){
    //             int ch=0;
    //             int su=0;
    //             TreeNode*t=q2.front();
    //             while(s2>0){
    //                 TreeNode*temp=q2.front();q2.pop();
    //                 // sum=sum-mp[temp->val];
    //                 if(mp[t->val]==mp[temp->val]&&t->val!=temp->val){
    //                     su=temp->val;
    //                 }
    //                 s2--;
                    
    //                 // cout<<mp[temp->val]<<" mp[temp->val] "<<temp->val<<" ";
    //             }
    //             t->val=sum-t->val-su;
    //             cout<<su<<" mp[temp->val] "<<t->val<<" ";
    //         }
    //         else{
    //             while(s2>0){
    //                 TreeNode*temp=q2.front();q2.pop();
    //                 temp->val=0;
    //                 s2--;
    //             }
    //         }

    //         while (!q2.empty()){
    //             q2.pop();
    //         }
    //         // mp.clear();
    //         lvl++;
    //     }
    //     return root;
    // }
    vector<int>arr;
    queue<TreeNode*>q;
    q.push(root);
    int lvl=0,sum=0;
    while(!q.empty())
    {
        int s=q.size();
        sum=0;
        while(s>0)
        {
            
            TreeNode*temp=q.front();q.pop();
            if(temp->left)
            {
                if(lvl>0){
                    sum+=temp->left->val;
                }
                q.push(temp->left);
            }
            if(temp->right)
            {
                if(lvl>0){
                    sum+=temp->right->val;
                }
                q.push(temp->right);
            }
            s--;
        }
        if(sum!=0)arr.push_back(sum);
        lvl++;
    }
    // int size=arr.size();
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }
    lvl=0;
    queue<TreeNode*>q1;
    q1.push(root);
    int i=0;
    int x=0;
    while(!q1.empty())
    {
        int s=q1.size();
        sum=0;
        x=0;
        int y=0;
        while(s>0)
        {
            
            TreeNode*temp=q1.front();q1.pop();
            x=0;
            y=0;
            if(temp->right) x=temp->right->val;
            if(temp->left) y=temp->left->val;
            if(temp->left)
            {
                if(lvl>0&&i<arr.size()){
                    temp->left->val=arr[i]-temp->left->val-x;
                }
                q1.push(temp->left);
            }
            
            if(temp->right)
            {
                if(lvl>0&&i<arr.size()){
                    temp->right->val=arr[i]-temp->right->val-y;
                }
                q1.push(temp->right);
            }
            if(lvl<2){
                temp->val=0;
            }
            s--;
        }
        if(lvl>0) i++;
        lvl++;
    }
    return root;
    }
};

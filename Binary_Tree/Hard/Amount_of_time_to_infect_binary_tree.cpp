// TC-> O(nlogn) coz we are using map which takes logn time to search, we can use unordered if hash collision doesn't occur (same hash value point to same index bucket)
// SC-> O(n)

class Solution {
public:
    TreeNode*createParentMapping(int target,TreeNode*root,map<TreeNode*,TreeNode*>&mp){//root to parent we cannot traverse so we created this mapping to calculate infection time
        TreeNode*res=NULL;

        queue<TreeNode*>q;
        q.push(root);
        mp[root]=NULL;
        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            if(front->val==target){
                res=front;

            }
            if(front->left){
                mp[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    int burnTheTree(map<TreeNode*,TreeNode*>&mp,TreeNode*root){
        map<TreeNode*,bool>visited;//map to check the particular node that we have visited
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        visited[root]=1;
        bool flag=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*front=q.front();
                q.pop();
                if(front->left&&!visited[front->left])
                {
                    flag=1;
                    q.push(front->left);
                    visited[front->left]=1;
                }
                if(front->right&&!visited[front->right])
                {
                    flag=1;
                    q.push(front->right);
                    visited[front->right] = 1; 
                }
                if(mp[front]&&!visited[mp[front]])
                {
                    flag=1;
                    q.push(mp[front]);
                    visited[mp[front]]=1;
                }
            }  
            if(flag==1){
                ans++;
                flag=0;
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        // create nodetoparent mapping
        // find the target node
        // burn the tree
        map<TreeNode*,TreeNode*>mp;
        TreeNode*target=createParentMapping(start,root,mp);
        int ans=burnTheTree(mp,target);
        return ans;

        
    }
};

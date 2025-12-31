class Solution {
public:
// SC is O(N) at complete binary tree queue will have N/2 nodes and for skewed tree we have size of vector equals to N
// TC is O(N)
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        
        vector<int>ans;
        while(!q.empty()){
            
            int size=q.size();
            int x=INT_MIN;

            while(size>0){
                TreeNode*temp=q.front();
                int z=temp->val;
                x=max(x,z);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                size--;
            }
            ans.push_back(x);
        }
        return ans;
    }
};

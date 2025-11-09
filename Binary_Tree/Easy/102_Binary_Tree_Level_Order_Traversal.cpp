class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {//tc nd sc -> O(N)
        
        vector<vector<int>>ans;
        if (!root) return ans;

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>t;
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(t);
                t.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                t.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};

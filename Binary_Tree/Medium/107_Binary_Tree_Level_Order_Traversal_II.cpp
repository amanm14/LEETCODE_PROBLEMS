class Solution { //O(N) tc nd sc
 //we can simply run level order traversal logic and use reverse(ans.begin(),ans.end()) at the last and return that 
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        vector<int>a;
        queue<TreeNode*>st;
        stack<TreeNode*>q;
        st.push(root);
        q.push(root);
        q.push(NULL);
        st.push(NULL);
        while(!st.empty()){
            TreeNode*temp=st.front();
            st.pop();
            if(temp==NULL){
                if(!st.empty()){
                    q.push(NULL);
                    st.push(NULL);
                }
            }
            else{
                q.push(temp);
                if(temp->left)st.push(temp->left);
                if(temp->right)st.push(temp->right);
            }
        }
        stack<int>s;
        while(!q.empty()){
            TreeNode*temp=q.top();
            q.pop();
            if(temp==NULL){
                while(!s.empty()){
                    a.push_back(s.top());
                    s.pop();
                }
                ans.push_back(a);
                a.clear();
                
            }
            else{
                s.push(temp->val);
                // if(temp->left)q.push(temp->left);
                // if(temp->right)q.push(temp->right);
            }
        }
        return ans;
    }
};

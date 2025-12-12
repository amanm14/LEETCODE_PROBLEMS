class Solution {
public: //O(N) sc and tc
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*ans=new TreeNode(val);
            ans->left=root;
            return ans;
        }
        queue<TreeNode*>q;
        int h=1;
        q.push(root);
        while(!q.empty()){
            
            int size=q.size();
            if(h==depth-1){
                while(size--){
                TreeNode*temp=q.front();
                q.pop();
                
                TreeNode* oldLeft = temp->left;
                    TreeNode* oldRight = temp->right;

                    temp->left = new TreeNode(val);
                    temp->left->left = oldLeft;

                    temp->right = new TreeNode(val);
                    temp->right->right = oldRight;
                }
                break;
            }
            
            

            while(size--){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            h++;
        }

        return root;
    }
};

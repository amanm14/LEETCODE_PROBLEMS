class Solution {
public:
    // TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // queue<TreeNode*>q;
        // q.push(cloned);
        // while(!q.empty()){
        //     TreeNode*temp=q.front();
        //     q.pop();
        //     if(q.front()==NULL){
        //         if(!q.empty()){
        //             q.push(NULL);
        //         }
        //     }
        //     else{
        //         if(temp->val==target->val){
        //             return temp;
        //         }
        //         if(temp->left){
        //             q.push(temp->left);
        //         }
        //         if(temp->right){
        //             q.push(temp->right);
        //         }
        //     }
        // }
        // return NULL; it will return the node but returned node is same this solution cannot be sure of that
        TreeNode* ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned == NULL)
            return cloned;
        if (cloned->val == target->val) // If target node found in cloned tree save it into a variable.
            ans = cloned;
        getTargetCopy(original, cloned->left, target);
        getTargetCopy(original, cloned->right, target);
        return ans;
    }
};

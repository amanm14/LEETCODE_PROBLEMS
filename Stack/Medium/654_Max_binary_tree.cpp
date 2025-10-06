class Solution {
public:
int find(int st,int e,vector<int>&nums){
    int ans=st;
    for(int i=st+1;i<=e;i++){
            if(nums[i]>nums[ans]){
               ans=i;
            }
    }
    return ans;
}
    TreeNode* make(int st,int e,vector<int>&nums){
        //O(n2) TC & SC O(n)
        if(st>e){
            return NULL;
        }

        int maIdx =find(st,e,nums);
        TreeNode* root = new TreeNode(nums[maIdx]);

        root->left=make( st,maIdx-1,nums);
        root->right=make(maIdx+1,e,nums);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // if(nums.empty()) return NULL;
        // return make(0,nums.size()-1,nums);
        stack<TreeNode*>st;//monotonic stack means i=either increasing or decreasing order
// O(N)&&O(n)
        for(int num:nums){
            TreeNode*temp=new TreeNode(num);
            while(!st.empty()&&st.top()->val<num){
                temp->left=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.top()->right=temp;
            }
            st.push(temp);
            
        }
        while(st.size()>1){
            st.pop();
        }
        return st.top();
    }
};

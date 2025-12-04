class Solution {
public: 
//O(N2) and O(N)

    // pair<int,int> solve(TreeNode* root) 
    // {
    //     if (root == NULL)
    //     {
    //         return {0,0};
    //     }
    //     pair<int,int>l=solve(root->left);
    //     pair<int,int>r=solve(root->right);
    //     int sum=root->val+l.first+r.first;
    //     int cnt=1+l.second+r.second;

    //     return {sum,cnt};
    // }

    // int averageOfSubtree(TreeNode* root) {
    //     pair<int,int>p;
    //     stack<TreeNode*>st;
    //     st.push(root);
    //     int count=0;

    //     while(!st.empty())
    //     {
    //         TreeNode*nd=st.top();
    //         st.pop();
    //         int z=1;
    //         pair<int,int> sum=solve(nd);
    //         int s=sum.first;
    //         int d=sum.second;

    //         d=s/d;
    //         if(d==nd->val)
    //         {
    //             count++;
    //         }
    //         if(nd->left) st.push(nd->left);
    //         if(nd->right) st.push(nd->right);

    //     }
    //     return count;
    // }

    // O(N) tc and sc
    // int count=0;
    pair<int,int> solve(TreeNode* root,int&count) 
    {
        if (root == NULL)
        {
            return {0,0};
        }
        pair<int,int>l=solve(root->left,count);
        pair<int,int>r=solve(root->right,count);
        int sum=root->val+l.first+r.first;
        int cnt=1+l.second+r.second;

        if(sum/cnt==root->val) count++;

        return {sum,cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int count=0;
        pair<int,int>p=solve(root,count);
        return count;
    }
};

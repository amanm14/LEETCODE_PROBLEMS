class Solution { 
//Time: O(n)
//Space: O(h) (O(log n) for balanced, O(n) for skewed)

// we can optimize this  as we are visiting tree twice that wwe can improve and visit only once to store data for both x and y


public:
    pair<int,int>solve(TreeNode*root,int x,int d){
        if(root==NULL){
            return make_pair(-1,0);
        }
        if(root->left&&root->left->val==x){
            return make_pair(root->val,d);
        }
        if(root->right&&root->right->val==x){
            return make_pair(root->val,d);
        }
        d++;
        pair<int,int>z1=solve(root->left,x,d);
        if(z1.first==-1){
             pair<int,int>z2=solve(root->right,x,d);
             return z2;
        }
        else return z1;
        

    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return 0;
        pair<int,int>z=solve(root,x,0);
        pair<int,int>z2=solve(root,y,0);
        cout<<z.first<<" space "<<z.second<<" "<<z2.first<<" "<<z2.second<<endl;
        if(z.first==-1||z2.first==-1) return 0;
        if(z.first!=z2.first&&z.second==z2.second) return 1;
        return 0;
    }
};

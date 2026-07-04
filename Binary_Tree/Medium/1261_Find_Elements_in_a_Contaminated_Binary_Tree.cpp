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
class FindElements {
public:

map<int,int>mp;
    void build(TreeNode*root,int cnt)
    {
        if(root==NULL) return;
        root->val=cnt;
        cout<<cnt<<" cnt "<<endl;
        mp[cnt]++;
        if(root->left){
            build(root->left,(cnt*2+1));
        }
        if(root->right){
            build(root->right,(cnt*2+2));
        }
        return;
    }
    FindElements(TreeNode* root) {
        int cnt=0;
        build(root,cnt);
        return;
    }
    
    bool find(int target) {
        if(mp.count(target)>0) return true;
        return false;

    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

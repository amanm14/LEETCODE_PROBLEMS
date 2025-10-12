
// TC and SC is very poor of this solution as we are not passing the string with the reference
//  which are taking extra space plus we concatinating the string each timme so worst casse vbecoming
//  O(nL)=O(n2) as L is size of string and SC is O(NLH)=O(n3) string *stack*string
// Worst-case (skewed tree): h = n → O(n^2)
// Balanced tree: h = log n → O(n log n)

// class Solution {
// public:
//     void solve(TreeNode*root,vector<string>&ans,string str){
//         if(!root){
//             return ;
//         }
        
//         if(str.empty()){
//         str=str+to_string(root->val);}//pr 3
//         else { str=str+"->"+to_string(root->val); } //pr1
//         solve(root->left,ans,str);
//         solve(root->right,ans,str);
//         if(root->left==NULL&&root->right==NULL)ans.push_back(str);//pr2
//         str=str.substr(0,str.size()-2);//pr4
//         return;
        
//     }
//     vector<string> binaryTreePaths(TreeNode* root) {
//          vector<string>ans;
//          string str="";
//         solve(root,ans,str);
//         return ans;
//     }
// };

// Total space = O(h + L * h) — improved from O(h^2 + L * h) h^2 coz string was not passed by refrence

class Solution {
public:
    void solve(TreeNode*root,vector<string>&ans,string&str){
        if(!root){
            return ;
        }
        int len=str.size();
        if(!str.empty()){
            str=str+"->";
        }
        str+=to_string(root->val);//pr 3
        solve(root->left,ans,str);
        solve(root->right,ans,str);
        if(root->left==NULL&&root->right==NULL)ans.push_back(str);//pr2
        str.resize(len);//pr4
        return;
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string>ans;
         string str="";
        solve(root,ans,str);
        return ans;
    }
};

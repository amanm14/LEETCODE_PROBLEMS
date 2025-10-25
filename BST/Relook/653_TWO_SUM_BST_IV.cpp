class BSTItretor{//SC-> O(H) which was O(N) in unordered_set
    stack<TreeNode*> store;
    bool isEnd = false;
    public:
    BSTItretor(TreeNode* root,bool isEnd){
        this->isEnd = isEnd;
        pushAll(root);
       
    }
    int next(){
        TreeNode* temp =store.top();
        store.pop();

        if(isEnd) 
        pushAll(temp->left);
        else
        pushAll(temp->right);
        return temp->val;
    }
    void pushAll(TreeNode* root){
         while(root){
            store.push(root);
            root =(isEnd)?root->right :root->left;
         }
    }


};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTItretor st(root,false);
        BSTItretor et(root,true);

        
        int i = st.next();
        int j = et.next();

        while(i<j){
          if(i + j == k) return 1;
          else if(i + j > k)j = et.next();
          else i = st.next();
        }

        return 0;
    }
};

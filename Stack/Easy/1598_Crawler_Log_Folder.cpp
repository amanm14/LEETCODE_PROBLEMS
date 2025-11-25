class Solution {
public: //O(N) nd O(N)
    int minOperations(vector<string>& logs) {
        stack<string>st;
        
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./"){
                // cout<<"st size "<<st.size()<<endl;
                continue;
            } 
            else if(logs[i]=="../"){
                if(st.empty()) continue;
                else st.pop();
                // cout<<"st size1 "<<st.size()<<endl;
            }
            else{  st.push(logs[i]);
                    // cout<<"st size "<<st.size()<<endl;
                }
        }
        // if(st.top()=="Main") return 0;
        return st.size();

    }
};

class Solution {
public:
    string removeDuplicates(string s) {//TC nd SC O(N) nD O(N)
        stack<char> st;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top() == s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }

        string result = "";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }

        reverse(result.begin(),result.end());
        return result;
        
    }
};

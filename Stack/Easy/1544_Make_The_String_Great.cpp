class Solution {
public:
// TC O(N) and SC O(N)
    string makeGood(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(!st.empty()){
                char x=st.top();
                char y=s[i];
                char x1=tolower(x);
                char y1=tolower(y);
                if(!st.empty()&&x!=y&&x1==y1)
                {
                    st.pop();
                }
                else
                {
                st.push(y);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

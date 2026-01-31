class Solution {
public://O(N) is tc and sc but we can do this in sc(1) by counting a and b and returning their abs difference
    int minLengthAfterRemovals(string s) {
        stack<char>st; 
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty()&&(st.top()=='b'&&s[i]=='a'||st.top()=='a'&&s[i]=='b')){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return st.size();
    }
};

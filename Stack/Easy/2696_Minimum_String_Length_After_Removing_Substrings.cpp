O(n) ->TC
O(n)-> SC
class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(!st.empty()){
                char x=st.top();
             if(x=='A'&&s[i]=='B'||x=='C'&&s[i]=='D'){
                    st.pop();
                    continue;//dont push current char point to note

             }
            }
            st.push(s[i]);
            
        }
       return st.size();
    }
};

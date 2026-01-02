class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st; //O(N) n is length of string is SC and TC we can use open and close variable to solve it in O(1) sc 
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty()&&s[i]==')'&&st.top()=='(') st.pop();
            else st.push(s[i]);
        }
    //     while(!st.empty()){
    //         if(st.top()=='('){
    //             op++;
    //             st.pop();
    //         }
    //     }
    // 
    return st.size();
    }
};

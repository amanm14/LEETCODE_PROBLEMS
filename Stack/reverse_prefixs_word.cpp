// TC->O(n)
// SC->(n)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char>st;
        string ans="";
        for(int i=0;i<word.length();i++){
             if(word[i]!=ch)st.push(word[i]);
            if(word[i]==ch){
                i++;
                st.push(ch);
                while(!st.empty()){
                    char temp=st.top();
                    st.pop();
                    ans.push_back(temp);
                }
                while(i<word.length()){
                    ans.push_back(word[i]);
                    i++;
                }
            }

        }
        return ans!=""?ans:word;
    }
};

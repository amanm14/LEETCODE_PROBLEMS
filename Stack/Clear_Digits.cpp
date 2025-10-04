// Time: O(n)
// Space: O(n)

class Solution {
public:
    string clearDigits(string s) {
        int n=s.length();
        string ans="";
        stack<char>st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                if(s[i]>47 &&s[i]<58){
                    char temp=st.top();
                    if(temp>96&&temp<123){
                        st.pop();
                    } 
                    else st.push(s[i]); 
                }
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};

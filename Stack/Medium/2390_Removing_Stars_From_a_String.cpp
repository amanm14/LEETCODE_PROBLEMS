class Solution {
public:
    string removeStars(string s) {
        string ans="";
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty()&&s[i]=='*'){
                st.pop();
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
//     string removeStars(string s) { //O(n) O(1)
//     int j = 0; // write pointer
    
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] == '*') {
//             j--;                // pop previous character
//         } else {
//             s[j] = s[i];        // write character
//             j++;
//         }
//     }

//     return s.substr(0, j);      // final valid string
// }
};

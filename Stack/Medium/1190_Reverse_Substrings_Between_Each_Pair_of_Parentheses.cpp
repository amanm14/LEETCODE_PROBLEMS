// class Solution {
// public:
//     string reverseParentheses(string s) {
//         string ans="";
//         string temp="";
//         stack<char>st;
//         string x="";
//         string y="";
//         int i1=0;
//         while(s[i1]!='('&&i1<s.length())
//         {
//             x+=s[i1++];
//         }
//         if(i1==s.length()) return s;
//         int j=s.length()-1;
//         while(s[j]!=')'&&j>=0){
//             y+=s[j--];
//         }
//         int j1=s.length()-j-1;
//         // cout<<"x "<<x<<" y "<<i1<<" -<i1 "<<j1<<" <-j1 ";
//         int cnt=0;
//         bool flag=false;
//         for(int i=i1;i<s.length()-j1;i++)
//         {
//             if(s[i]==')')
//             {
//                 while(!st.empty()&&st.top()!='('){
//                     temp+=st.top();
//                     st.pop();
//                 }
//                 if(!st.empty())st.pop();
//                 if(!st.empty()){
//                     // reverse(temp.begin(),temp.end());
//                     for(int i1=0;i1<temp.length();i1++)
//                     {
//                       st.push(temp[i1]);
//                     }
//                     temp="";
//                 }
//                 else{
//                     // reverse(temp.begin(),temp.end());
//                     ans=temp;
//                 }
//             }
//             else
//             {
//                 if(flag==true) st.push(s[i]);
//                 if(s[i]=='(') flag=true;
//             }

//         }
//         // cout<<ans<<" <-ans ";
//         if(x.length()>0){
//             string t=ans;
//             ans="";
//             ans=x+t;
//             // cout<<" ans "<<ans<<" ";
//         }
//         if(y.length()>0){
//             string t=ans;
//             ans="";
//             ans=t+y;
//             // cout<<" ans "<<ans<<" ";
//         }
//         return ans;
//     }
// };

class Solution {
int i = 0;
public://O(N) is tc an sc
    string reverseParentheses(string s) {
        return helper(s);
    }

    string helper(string& s) {
        string result;

        while (i < s.length()) {
            if (s[i] == ')') {
                i++;
                reverse(result.begin(), result.end());
                return result;
            } else if (s[i] == '(') {
                i++;
                string st = helper(s); //recursion used in this question
                result += st;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};

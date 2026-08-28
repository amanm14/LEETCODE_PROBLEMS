// class Solution {
// public://O(n^2log(3[a,b,c])) is tc and sc is O(1)
//     int numberOfSubstrings(string s) {
//         int cnt=0;
//         map<char,int>mp;
//         string newstr="";
//         for(int i=0;i<s.length();i++)
//         {
//             for(int j=i;j<s.length();j++)
//             {
//                 mp[s[j]]++;
//                 if(mp.find('a')!=mp.end()&&mp.find('b')!=mp.end()&&mp.find('c')!=mp.end())
//                 {
//                     cnt++;
//                 }
//             }
//             mp.clear();
//         }
//         return cnt;
//     }
// };

class Solution {
public://O(n) is tc and O(1) is sc
    int numberOfSubstrings(string s) {

        int last[3] = {-1, -1, -1};
        int ans = 0;

        for(int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;

            if(last[0] != -1 &&
               last[1] != -1 &&
               last[2] != -1)
            {
                int mini = min({last[0], last[1], last[2]});

                ans += mini + 1;
            }
        }

        return ans;
    }
};

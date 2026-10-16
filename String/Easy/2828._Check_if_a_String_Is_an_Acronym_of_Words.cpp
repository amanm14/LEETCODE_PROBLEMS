class Solution {
public://O(n) is tc and sc is O(words.size())
    bool isAcronym(vector<string>& words, string s) {
        return s == [words]{ string r; for(auto& w : words) r += w[0]; return r; }();   
    }
{
// if(words.size()!=s.length()) return false; //O(n) is tc and sc is O(1)
//   for(int i=0;i<s.length();i++)
//     {
//         if(words[i][0]!=s[i]) return false;
//     }
//   return true;
// }
};

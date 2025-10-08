// TC -> O(n)
// SC -> O(n)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>ump;
        for(int i=0;i<s.length();i++){
               if(ump.find(s[i])==ump.end()||ump[s[i]]==t[i]) ump[s[i]]=t[i];
               else return false;
        }
        unordered_map<char,char>ump1;
        for(int i=0;i<t.length();i++){
               if(ump1.find(t[i])==ump1.end()||ump1[t[i]]==s[i]) ump1[t[i]]=s[i];
               else return false;
        }
        return true;
    }
};

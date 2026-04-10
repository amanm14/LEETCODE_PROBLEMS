class Solution {
public://O(n) is tc and O(1)
    string findValidPair(string s) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        for(int i=1;i<s.length();++i){
            if(s[i]!=s[i-1] && freq[s[i]]==(s[i]-'0')&& freq[s[i-1]]==(s[i-1]-'0')){
                return s.substr(i-1,2); //(position,length)
            }
        }
        return "";
    }
};

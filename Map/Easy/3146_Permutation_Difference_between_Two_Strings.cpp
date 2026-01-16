class Solution {
public://O(n) tc and O(1) sc as we have 26 letters only
    int findPermutationDifference(string s, string t) {
        map<char,int>mp;
        int ans=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        for(int i=0;i<t.length();i++){
            ans=ans+abs(mp[t[i]]-i);
        }
        return ans;
    }
};

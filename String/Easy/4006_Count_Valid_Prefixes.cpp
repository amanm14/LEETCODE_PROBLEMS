class Solution {
public://O(n) is tc and sc is O(1)
    int countValidPrefixes(string s) {
        int c1=0,c2=0,ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')c1++;
            else c2++;
            if(c1-1==c2||c1==c2-1||c1==c2) ans++;     
        }
        return ans; 
    }
};

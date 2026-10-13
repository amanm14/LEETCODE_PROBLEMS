class Solution {
public://O(n) is tc ans sc is O(1)
    char repeatedCharacter(string s) {
        vector<char>a(27,0);
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]-'a']!=0) return s[i];
            a[s[i]-'a']=1;
        }   
        return '0';
    }
};

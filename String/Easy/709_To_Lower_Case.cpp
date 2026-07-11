class Solution {
public://O(n) is tc and sc is O(1)
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a'&&s[i]<='z'){
                continue;
            }
            s[i]=tolower(s[i]);
        }
        return s;
    }
};

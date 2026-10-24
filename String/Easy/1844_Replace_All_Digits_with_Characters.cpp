class Solution {
public://O(n) is tc and sc is O(1) leving te auxiliary space that we are tking O(s.length())
    string replaceDigits(string s) {
        string a="";
        for(int i=1;i<s.length();i++)
        {
            char t=s[i-1];
            a.push_back(t);
            int t1=(s[i])-'0';
            a.push_back(t+t1);
            i++;

        }
        if((s.length())%2!=0) a.push_back(s[s.length()-1]);
        return a;
    }
};

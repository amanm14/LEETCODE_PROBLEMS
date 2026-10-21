class Solution {
public://O(n) is tc and sc is O(1)
    string trimTrailingVowels(string s) {
        int j=0;
        bool f=false;
        for(int i=s.length()-1;i>=0;i--)
        {
            j=i;
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                f=true;
            }
            else break;
           
        }
        int i=j;
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            return "";
        }
        return s.substr(0,j+1);
    }
};

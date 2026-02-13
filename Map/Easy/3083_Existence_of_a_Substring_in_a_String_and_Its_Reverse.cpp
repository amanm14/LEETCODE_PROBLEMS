class Solution {
public://tc O(nlogn) and sc O(n) 
    bool isSubstringPresent(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        map<string,int>m1;
        for(int i=1;i<s1.length();i++)
        {
            string z="";
            z+=s1[i];
            z+=s1[i-1];
            // cout<<z;
            m1[z]++;
        }
        for(int i=1;i<s.length();i++)
        {
            string z="";
            z+=s[i];
            z+=s[i-1];
            if(m1[z]>0){
                return true;
            }
        }
        return false;
    }
};

class Solution {
public://O(n) is tc and sc other auxiliary sc is O(a.length())
    string maximumOddBinaryNumber(string s) {
        int o=0,z=0;
        string a="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1') o++;
            else z++;
            
        }
        if(o==0) return s;
        else if(o==1)
        {
            for(int i=0;i<s.length()-1;i++) a.push_back('0');
            a.push_back('1');
            return a;
        }
        else{
            while(o>1){
                a.push_back('1');
                o--;
            }
            while(z!=0)
            {
                a.push_back('0');
                z--;
            }
            a.push_back('1');
            return a;
        }
    }
};

class Solution {
public://O(n^2) is tc and sc is O(n) and it can be optimised o O(1) sc by doing inplace runing decreament while loop over n that is size >2and decreading thte n then storing the two char at i and i+1 at i by converting them to numbers by adding + '0' 
    bool hasSameDigits(string s) {
        string z="";
        while(s.length()>2)
        {
            // z=s;
            for(int j=1;j<s.length();j++)
            {
                int x;
                char i1=s[j];
                char i2=s[j-1];
                x=i1-'0';
                x+=i2-'0';
                x=x%10;
                z.push_back(x+'0');
            }
            s=z;
            z.clear();
        }
        return s[0]==s[1];
    }
};

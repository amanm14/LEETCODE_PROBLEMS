class Solution {
public://O(n) is tc and O(1) is sc
    int balancedStringSplit(string s) {
        int ans=0,b=0;
        for(char i:s)
        {
            if(i=='R') b++;
            else b--;

        if(b==0) ans++;
        }
        return ans;
    }
};

class Solution {
public://O(n) is tc and sc is O(1)
    int countRotations(string s, int k) {
        string z=s;
        char p=s[0];
        int n=s.length(),ans=0,cnt=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==p) cnt++;
            p=s[i];
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[(i+1)%n]) cnt--;
            if(p==s[i]) cnt++;
            p=s[i];
            if(cnt==k) ans++;
        }
        return ans;
    }
};

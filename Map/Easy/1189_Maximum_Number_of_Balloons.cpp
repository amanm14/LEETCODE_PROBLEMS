class Solution {
public://O(N) as logk for insertion in map is constant coz we have k=26 and O(n) is sc
    int maxNumberOfBalloons(string text) {

        map<char,int>mp;
        int ans=INT_MAX;

        for(int i=0;i<text.length();i++)
        {
            mp[text[i]]++;
        }

        if(mp['b']<1||mp['a']<1||mp['l']<2||mp['o']<2||mp['n']<1) return 0;
        
        for(auto i:mp)
        {
            if(i.first=='b'||i.first=='a'||i.first=='l'||i.first=='l'||i.first=='o'||i.first=='o'||i.first=='n'){
                ans=min(ans,i.second);
            }
            

        }
        int l1=mp['l'];
        int l2=mp['o'];
        int x=min(l1,l2);
        ans=min(ans,x/2);

        return ans;
    }
};

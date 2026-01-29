class Solution {
public:
// Worst case → O(n + 26²) ≈ O(n)

// Space = O(d) → O(1)

    int minDeletion(string s, int k) {
        map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        if(mp.size()==k) return 0;
        int ans=0;
        int z=mp.size();
        // cout<<z<<" ";
        while(z>k){
                // cout<<" k ";
                int m=INT_MAX;
                char ma=' ';
                for(auto i:mp){
                    if(m>i.second){
                        m=i.second;
                        ma=i.first;
                    }
                }
                mp.erase(ma);
                // cout<<"m "<<m<<" "<<ma<<" ";
                ans=ans+m;
                z--;
        }
        return ans;
    }
};

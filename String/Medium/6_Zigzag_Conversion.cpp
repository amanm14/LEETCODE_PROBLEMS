class Solution {
public://O(n log(numRows))) is t c and sc is o(n) and its tc can be made to O(N) just using vectro<string>z(numRows) instead of map
    string convert(string s, int numRows) {
        map<int,string>mp;
        int z=0;

        for(int i=0;i<s.length();){
            cout<<z<<" tope "<<endl;
            while(z<numRows&&i<s.length())
            {
                mp[z].push_back(s[i]);
                i++;
                z++;
            }
            z--;
            z--;
            if(z<0) z=0;
            while(z>0&&i<s.length())
            {
                mp[z].push_back(s[i]);
                i++;
                z--;
            }
            
            // z++;
            cout<<z<<endl;
        }
        string ans="";
        for(auto it:mp){
            ans+=(it.second);
            cout<<it.second<<endl;
        }
        return ans;
    }
};

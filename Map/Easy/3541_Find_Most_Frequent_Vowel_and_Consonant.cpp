class Solution {
public:??tc is O(nlogn) and O(n) is sc
    int v=0;
    int c=0;
    map<char,int>mp;
    int maxFreqSum(string s) {
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto i:mp){
            if(i.first=='a'||i.first=='e'||i.first=='i'||i.first=='o'||i.first=='u'){
                c=max(c,i.second);
            }
            else{
                v=max(v,i.second);
            }
        }
return (c+v);
    }
    
};

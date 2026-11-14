class Solution {
public://O(nlogk) is tc and sc is O(1)
    bool areOccurrencesEqual(string s) {
        map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        int p=-1;
        for(auto i:mp)
        {
            if(p!=-1)
            {
                if(p!=i.second) return false;
            }
            p=i.second;
        }
        return true;
    }
};//we can do it in O(n) tc ans sc O(1) by takin vector of size 26 to store all the chars and nums to track count and compare each coun

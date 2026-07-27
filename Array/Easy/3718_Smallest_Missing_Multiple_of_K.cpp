class Solution {
public://O(nlogn) ans sc is O(n)
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums) mp[it]++;
        int cnt=0,ko=k;
        while(mp.find(ko)!=mp.end())
        {
            cnt++;
            ko=k*cnt;
            // cout<<"k "<<k<<" cnt "<<cnt<<endl;
        }
        return ko;
    }
};

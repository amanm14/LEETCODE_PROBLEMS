class Solution {
public://O(nlogn) is tc and O(N) is sc
    int maxFrequencyElements(vector<int>& nums) {
        int m=0;
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            m=max(m,i.second);
        }
        for(auto i:mp){
            if(i.second==m) ans+=i.second;
        }
        return ans;
    }

};

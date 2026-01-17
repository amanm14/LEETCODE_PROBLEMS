class Solution {
public: //tc is O(NlogN) and sc O(n)
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        for(auto i:mp)
        {
            if(i.second%k==0) ans=ans+(i.first*i.second);
        }

        return ans;
    }
};

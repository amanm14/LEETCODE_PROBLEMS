class Solution {
public://O(nlogn) is tc and O(n) is sc
    int sumOfUnique(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int cnt=0;
        for(auto i:mp){
            if(i.second==1){
                cnt+=i.first;
            }
        }
        return cnt;
    }
};

class Solution {
public://O(NlogN) is tc and O(N) is sc
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        map<int,int>mp;
        sort(nums.begin(),nums.end());
        vector<int>ans;
        // reverse(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0&&k>0;i--){
            if(mp.count(nums[i])==0){
                ans.push_back(nums[i]);
                k--;
            }
            mp[nums[i]]++;
            
        } 
        
        return ans;
    }
};

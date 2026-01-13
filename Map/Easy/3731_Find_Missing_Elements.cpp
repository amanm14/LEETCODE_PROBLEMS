class Solution {
public://O(NlogN) tc and O(N) sc
    vector<int> findMissingElements(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        int m=INT_MAX;
        int ma=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            m=min(nums[i],m);
            ma=max(nums[i],ma);

        }  
        for(int i=m;i<=ma;i++){
            if(mp.count(i)>0){
                continue;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class Solution {
public://O(nlogn) is tc and O(N) is sc
    int majorityElement(vector<int>& nums) {
        int size=nums.size();
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>size/2){
                return nums[i];
            }
        }
        return -1;
    }
};

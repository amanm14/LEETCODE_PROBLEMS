class Solution {
public://O(nlogn) is tc and O(1) is sc
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mi=nums[0];
        int ma=nums[nums.size()-1],cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(ma!=nums[i]&&mi!=nums[i]){
                cnt=nums[i];
                break;
            }
        }
        if(cnt==0) cnt=-1;
        return cnt;
    }
};

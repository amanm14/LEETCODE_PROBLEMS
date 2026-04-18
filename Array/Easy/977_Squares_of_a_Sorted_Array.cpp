class Solution {
public://O(nlogn) is tgsc and O(1) is sc->O(logn) as sort uses this space
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        int i=0;
        int j=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
        
    }
};

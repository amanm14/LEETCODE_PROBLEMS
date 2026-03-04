class Solution {
public://0(n) is tc and O(1) is sc
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1,last=-1;

        for(int i=0;i<nums.size();i++) {
            if(nums[i]==target && first==-1){
                first = i;
                last=i;
            } else if(nums[i]==target) {
                last = i;
            }
        } 

        return {first,last};
        
    }
};

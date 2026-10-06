class Solution {
public://O(n*log(m)) is tc and sc is O(1) we can not double it like n times we can only do it log m times
//So you can only double around 30 times, regardless of whether n = 1000 or n = 1,000,000
    int findFinalValue(vector<int>& nums, int original) {
        
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==original)
                {
                    original*=2;
                    i=-1;
                }
            }
            return original;
    }
};

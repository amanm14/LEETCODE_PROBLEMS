class Solution {
public://O(N3) and O(1)
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int sz = nums.size();
        int cnt = 0;
        for(int i = sz-1; i >= 2; --i)
        {
            for(int j = sz-2; j >= 1; --j)
            {
                for(int k = sz-3; k >= 0; --k)
                {
                    if(nums[i]-nums[j] == diff && nums[j]-nums[k] == diff)
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};

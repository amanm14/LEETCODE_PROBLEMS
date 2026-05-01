class Solution {
public://0(n) is tc nd o(1) is sc
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};

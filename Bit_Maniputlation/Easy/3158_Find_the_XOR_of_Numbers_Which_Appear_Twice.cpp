class Solution {
public://O(Nlogn) is tc and O(1) is sc
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                ans ^= nums[i];
            }
        }
        return ans;
    }
};

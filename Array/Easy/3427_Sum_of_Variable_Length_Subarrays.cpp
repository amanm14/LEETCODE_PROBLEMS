class Solution {
public://O(n) is tc and sc
    int subarraySum(vector<int>& nums) {

        int n = nums.size();

        vector<int> ps(n + 1, 0);

        for(int i = 0; i < n; i++){
            ps[i + 1] = ps[i] + nums[i];
        }

        int ans = 0;

        for(int i = 0; i < n; i++){

            ans += ps[i + 1] - ps[max(0, i - nums[i])];
        }

        return ans;
    }
};

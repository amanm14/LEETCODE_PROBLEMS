class Solution {
public://O(n) is tc and sc  o(1)
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int cnt = 0;
        int ans = 0;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == 0)
                cnt++;

            while(cnt > 1) {
                if(nums[i] == 0)
                    cnt--;
                i++;
            }

            ans = max(ans, j - i);
        }

        return ans;
    }
};

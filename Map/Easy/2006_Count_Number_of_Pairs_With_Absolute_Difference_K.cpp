class Solution {
public://O(n) is tc and O(n) is sc
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans = 0;

        for(int n : nums){
            ans += m[n - k]; // count elements with difference k (smaller side)
            ans += m[n + k]; // count elements with difference k (larger side)
            m[n]++;          // store current number
        }

        return ans;
    }
};

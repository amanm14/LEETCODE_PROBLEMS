class Solution {
public://o(n) is tc  and O(1) is sc
    int reverseDegree(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += (26 - (s[i] - 'a')) * (i + 1);
        }
        return ans;
    }
};

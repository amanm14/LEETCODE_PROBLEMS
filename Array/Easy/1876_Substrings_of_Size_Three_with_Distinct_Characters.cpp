class Solution {
public://O(n) is tc and sc is O(1)
    int countGoodSubstrings(string s) {
        if (s.length() < 3) return 0;
        int cnt = 0;
        
        // Check every starting position 'i' for a valid window of 3
        for (int i = 0; i <= s.length() - 3; i++) {
            if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) {
                cnt++;
            }
        }
        return cnt;
    }
};

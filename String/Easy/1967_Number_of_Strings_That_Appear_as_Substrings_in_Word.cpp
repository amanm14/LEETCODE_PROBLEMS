class Solution {
public://O(N*L*M) is tc and sc is O(1)
// n = number of patterns
// m = average pattern length
// L = length of word
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (string &p : patterns) {
            if (word.find(p) != string::npos)
                ans++;
        }

        return ans;
    }
};

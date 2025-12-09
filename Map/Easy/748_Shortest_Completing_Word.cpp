class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> need(26, 0);

        // Count required letters from license plate
        for (char c : licensePlate) {
            if (isalpha(c)) {
                need[tolower(c) - 'a']++;
            }
        }

        string best = "";
        
        for (string &w : words) {
            vector<int> cnt(26, 0);

            for (char c : w)
                cnt[c - 'a']++;

            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < need[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (best == "" || w.length() < best.length()) {
                    best = w;
                }
            }
        }

        return best;
    }
};

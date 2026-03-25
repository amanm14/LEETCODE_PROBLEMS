class Solution {
public://O(N) is tc and sc
    int maxLengthBetweenEqualCharacters(std::string s) {
        unordered_map<char, int> lastOccurrence;
        int maxLength = -1;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (lastOccurrence.count(c)) {
                maxLength = max(maxLength, i - lastOccurrence[c] - 1);
            } else {
                lastOccurrence[c] = i;
            }
        }

        return maxLength;
    }
};

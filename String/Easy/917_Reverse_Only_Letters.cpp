class Solution {
public://o(n) tc and sc
    string reverseOnlyLetters(string s) {
        string letters;

        // Store all letters
        for (char c : s) {
            if (isalpha(c)) {
                letters += c;
            }
        }

        // Reverse the letters
        reverse(letters.begin(), letters.end());

        // Put reversed letters back
        int index = 0;

        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                s[i] = letters[index++];
            }
        }

        return s;
    }
};

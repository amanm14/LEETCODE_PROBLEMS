#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;


//O(n) TC nd SC
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp;       // pattern char -> word
        map<string, char> used;     // word -> pattern char (to ensure 1-1 mapping)
        stringstream ss(s);
        string word;
        vector<string> words;

        // Split string into words
        while (ss >> word)
            words.push_back(word);

        // If pattern and words count differ
        if (pattern.size() != words.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            // If mapping already exists
            if (mp.count(c)) {
                if (mp[c] != w)
                    return false;  // mismatch
            } else {
                // if word already used by another character
                if (used.count(w))
                    return false;
                mp[c] = w;
                used[w] = c;
            }
        }

        return true;
    }
};

class Solution {
public: //TC (N+M) SC(n+m)
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (!st1.empty()) st1.pop();
            } else {
                st1.push(s[i]);
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '#') {
                if (!st2.empty()) st2.pop();
            } else {
                st2.push(t[i]);
            }
        }

        string str1 = "", str2 = "";

        while (!st1.empty()) {
            str1 += st1.top();
            st1.pop();
        }

        while (!st2.empty()) {
            str2 += st2.top();
            st2.pop();
        }

        return str1 == str2;
    }
};

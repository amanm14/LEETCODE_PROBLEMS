class Solution {
public: //O(N2) and SC O(N)
    string removeOccurrences(string s, string part) {
    stack<char> st;

    for (char c : s) {
        st.push(c);

        // check if top of stack ends with part
        if (st.size() >= part.size()) {
            string temp = "";
            stack<char> tempSt = st;

            for (int i = 0; i < part.size(); i++) {
                temp += tempSt.top();
                tempSt.pop();
            }
            reverse(temp.begin(), temp.end());

            if (temp == part) {
                for (int i = 0; i < part.size(); i++)
                    st.pop();
            }
        }
    }

    // build result
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

};

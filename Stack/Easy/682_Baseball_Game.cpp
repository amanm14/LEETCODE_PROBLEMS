class Solution {
public:
    int calPoints(vector<string>& operations) {
    stack<int> st;//TCS-> O(N)  SC->O(N)

    for (auto &op : operations) {
        if (op == "C") {
            st.pop();
        } else if (op == "D") {
            st.push(st.top() * 2);
        } else if (op == "+") {
            int last = st.top(); st.pop();
            int newScore = last + st.top();
            st.push(last);          // restore last
            st.push(newScore);      // add new score
        } else {
            st.push(stoi(op));      // convert string to integer
        }
    }

    int total = 0;
    while (!st.empty()) {
        total += st.top();
        st.pop();
    }

    return total;
}

};

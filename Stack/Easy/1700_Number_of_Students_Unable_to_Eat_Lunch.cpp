class Solution {
// int countStudents(vector<int>& students, vector<int>& sandwiches) {
//     queue<int> q;
//     for (int s : students) q.push(s);
//     int j = 0;
//     int count = 0;

//     while (!q.empty() && count < q.size()) {
//         if (q.front() == sandwiches[j]) {
//             q.pop();
//             j++;
//             count = 0; // reset since someone ate
//         } else {
//             q.push(q.front());
//             q.pop();
//             count++;
//         }
//     }
//     return q.size();
// } // Although it solve question but at worst case it will run 10*n which is not good also we are extending students size we are using O(N ) space 
// so we can use better optimised and clear approach
public:
//TC nd SC-> O(N) and O(N)
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    stack<int> st;

    // Fill the stack (reverse order, because top is served first)
    for (int i = sandwiches.size() - 1; i >= 0; i--) {
        st.push(sandwiches[i]);
    }

    for (int s : students)
        q.push(s);

    int failed = 0;

    while (!q.empty() && !st.empty()) {
        if (q.front() == st.top()) {
            q.pop();
            st.pop();
            failed = 0; // reset, someone ate
        } else {
            q.push(q.front());
            q.pop();
            failed++;
        }

        if (failed == q.size()) break; // full rotation, no one ate
    }

    return q.size(); // students left
}
};

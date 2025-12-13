// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int>ans;
//         for(int i=0;i<temperatures.size();i++){
//             int count=0;
//             bool flag=true;
//             for(int j=i+1;j<temperatures.size();j++){
//                 if(temperatures[i]<temperatures[j]){
//                     count++;
//                     flag=false;
//                     break;
//                 }
//                 count++;
//                 // if(j==temperatures.size()-1) flag=false
//             }
//             if(flag==false){
//                 ans.push_back(count);
//                 flag=true;
//             }
//             else ans.push_back(0);
//         }
//         return ans;
//     }
// };
class Solution {
public://O(N) sc and tc
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // store indices

        for (int i = 0; i < n; i++) {

            // resolve previous colder days
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }

            st.push(i);
        }

        return ans;
    }
};

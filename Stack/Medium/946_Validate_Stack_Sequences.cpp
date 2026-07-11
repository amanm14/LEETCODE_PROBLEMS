// class Solution {
// public: //passed 101 use case based on asumption of relatoin shi between a[i] and b[n-i-1]
//     bool validateStackSequences(vector<int>& a, vector<int>& b) {
//         int n=a.size();
//         int idx=0;
//         for(int i=0;i<n;i++)
//         {
//             if(a[i]==b[n-i-1]) continue;
//             else{
//                 int prev=-1;
//                 while(i<n&&a[i]!=b[n-i-1])
//                 {
//                     // cout<<a[i]<<" "<<b[idx]<<endl;
//                     if(a[i]!=b[idx]){
//                         if(prev!=-1&& a[i]<=prev){
//                             i++;
//                         }
//                         else return false;
//                     }
//                     else{
//                         prev=max(prev,b[n-i-1]);
//                         i++;
//                         idx++;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };
class Solution {
public://O(n) is tc and sc
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;

        for (int x : pushed) {
            st.push(x);

            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};

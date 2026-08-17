class Solution {
public://O(n*|k|) is tc and sc O(n), its best optimize soltion is O(n)  using the sliding window
    vector<int> decrypt(vector<int>& code, int k) {
        int fans=0;
        vector<int>ans;
        for(int i=0;i<code.size();i++)
        {
            int t=k,idx=i;
            int tsum=0;
            while(t>0)
            {
                idx++;
                if(idx==code.size())
                {
                    idx=0;
                }
                tsum+=code[idx];
                
                t--;
            }
            while(t<0){
                idx--;
                if(idx<0)
                {
                    idx=code.size()-1;
                }
                tsum+=code[idx];
                
                t++;
            }
            ans.push_back(tsum);
        }
        return ans;
    }
};

// its O(n) appproach is like this 

// class Solution {
// public:
//     vector<int> decrypt(vector<int>& code, int k) {
//         int n = code.size();
//         vector<int> ans(n, 0);

//         if(k == 0)
//             return ans;

//         int window = 0;

//         // k > 0
//         if(k > 0)
//         {
//             // Initial window: next k elements for index 0
//             for(int j = 1; j <= k; j++)
//             {
//                 window += code[j % n];
//             }

//             for(int i = 0; i < n; i++)
//             {
//                 ans[i] = window;

//                 // Remove old element
//                 window -= code[(i + 1) % n];

//                 // Add new element
//                 window += code[(i + k + 1) % n];
//             }
//         }

//         // k < 0
//         else
//         {
//             k = -k;  // make k positive

//             // Initial window: previous k elements for index 0
//             for(int j = 1; j <= k; j++)
//             {
//                 window += code[(n - j) % n];
//             }

//             for(int i = 0; i < n; i++)
//             {
//                 ans[i] = window;

//                 // Remove old element
//                 window -= code[(i - k + n) % n];

//                 // Add new element
//                 window += code[i];
//             }
//         }

//         return ans;
//     }
// };

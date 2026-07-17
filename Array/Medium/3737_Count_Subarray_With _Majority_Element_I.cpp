// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         // int ans=0;
//         // for(int i=0;i<num.size();i++)
//         // {
//         //     int t=0;
//         //     while(nums[i]==target) t++;
//         //     ans+=pow(2,t);
//         // }
//         // int a=0;
//         // vector<int>arr;
//         // for(int i=0;i<num.size();i++)
//         // {
//         //     if(nums[i]==target) a++;
//         //     int n=arr.size();

//         // }
//         int ans=0;
//         for(int i=0;i<=nums.size();i++)
//         {
//             int window=i;
//             int s=0;
//             int e=0;
//             int cnt=0;
//             while(e<nums.size())
//             {
//                 while(e<=i&&e<nums.size()){
//                     if(nums[e]==target) cnt++;
//                     e++;
//                 }
//                 if(e>=nums.size()) break;
//                 if(nums[e]==target) cnt++;
//                 if(((e-s+1)/2)<cnt)
//                 {
//                     ans++;
//                 }
//                     s++;
//                     e++;
//                     if(nums[s-1]==target) cnt--;
                
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public://O(n^2) is tc annd sc is O(1) 
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            int freq = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    freq++;
                }

                int len = j - i + 1;

                if (freq > len / 2) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};


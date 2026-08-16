// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int ans=0,temp=0,j=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]%2!=0)
//             {
//                 temp++;
//             }
//             if(temp==k)
//             {
//                 ans+=i-j+1;
//                 if(nums[j]%2!=0) temp--;
//                 j++;
//                 cout<<ans<<endl;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public://O(n) is tc and O(1) is sc
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, oddCount = 0, left = 0;
        int currentCount = 0; // Tracks consecutive even numbers at the start of the window

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 != 0) {
                oddCount++;
                currentCount = 0; // Reset because we hit a new odd number
            }

            // Shrink the window while we have exactly k odd numbers
            while (oddCount == k) {
                currentCount++; // Every increment here represents a valid subarray ending at 'right'
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }
            
            // Add the number of valid subarrays found
            ans += currentCount;
        }
        return ans;
    }
};

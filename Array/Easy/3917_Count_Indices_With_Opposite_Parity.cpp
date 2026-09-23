// class Solution {
// public:
//     vector<int> countOppositeParity(vector<int>& nums) {
//         vector<int>ans;
//         for(int i=0;i<nums.size();i++)
//         {
//             int cnt=0;
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if(nums[i]%2==0&&nums[j]%2!=0) cnt++;
//                 else if(nums[i]%2!=0&&nums[j]%2==0) cnt++;
//             }
//             ans.push_back(cnt);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int even = 0, odd = 0;

        // Count total even and odd
        for(int x : nums) {
            if(x % 2 == 0)
                even++;
            else
                odd++;
        }

        for(int i = 0; i < n; i++) {

            // Remove current element because
            // we only want elements AFTER i
            if(nums[i] % 2 == 0) {
                even--;
                ans[i] = odd;
            }
            else {
                odd--;
                ans[i] = even;
            }
        }

        return ans;
    }
};

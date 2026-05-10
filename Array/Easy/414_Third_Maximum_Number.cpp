// class Solution {
// public://O(nlogn) is tc and O(1) is sc
//     int thirdMax(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int ans=nums[nums.size()-1],cnt=1;
//         int ch=ans;
//         for(int i=nums.size()-1;i>=0;i--){
//             if(i-1>=0&&nums[i-1]!=nums[i]){
//                  cnt++;
//             }
//             if(cnt==3){
//                 return nums[i-1];
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public://O(n) is t and O(1) is sc
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int num : nums) {

            // skip duplicates
            if (num == first || num == second || num == third) {
                continue;
            }

            if (num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if (num > second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }
        }

        return (third == LLONG_MIN) ? first : third;
    }
};

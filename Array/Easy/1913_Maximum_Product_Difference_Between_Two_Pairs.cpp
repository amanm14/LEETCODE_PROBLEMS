// class Solution {
// public://O(nlogn) is tc
//     int maxProductDifference(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size()-1;
//         return abs((nums[0]*nums[1])-(nums[n]*nums[n-1]));
//     }
// };
class Solution {
public://O(n) is tc and sc is O(1)
    int maxProductDifference(vector<int>& nums) {
        int largest = 0, secondLargest = 0;
        int smallest = INT_MAX, secondSmallest = INT_MAX;

        for (int n : nums) {
            if (n < smallest) {
                secondSmallest = smallest;
                smallest = n;
            } else if (n < secondSmallest) {
                secondSmallest = n;
            }

            if (n > largest) {
                secondLargest = largest;
                largest = n;
            } else if (n > secondLargest) {
                secondLargest = n;
            }
        }

        return (largest * secondLargest) - (smallest * secondSmallest);
    }
};

// class Solution {
// public://O(n^2) is tc and O(1) is sc
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int j=0,cnt=0,s=0;
//         bool flag=false;
//         for(int i=0;i<nums.size();i++)
//         {
//             s=0;
//             for(int j=i;j<nums.size();j++)
//             {
//                 s+=nums[j];
//                 if(s==goal) cnt++;
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     // O(n) TC and O(n) SC
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         unordered_map<int, int> mp;
        
//         mp[0] = 1;

//         int sum = 0;
//         int cnt = 0;

//         for(int i = 0; i < nums.size(); i++) {
//             sum += nums[i];

//             if(mp.find(sum - goal) != mp.end()) {
//                 cnt += mp[sum - goal];
//             }

//             mp[sum]++;
//         }

//         return cnt;
//     }
// };

class Solution {
public://O(n) is tc and sc is O(1)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;

        int i = 0, sum = 0, cnt = 0;

        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while(sum > goal) {
                sum -= nums[i++];
            }

            cnt += j - i + 1;
        }

        return cnt;
    }
};

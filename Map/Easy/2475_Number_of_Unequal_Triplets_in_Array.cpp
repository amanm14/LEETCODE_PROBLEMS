class Solution {
public://O(N3) is tc and sc is O(1)
    int unequalTriplets(vector<int>& nums) {
        int m=0;
        // if(n>=3)
        // {
           for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if( nums[i] != nums[j]&&nums[i] != nums[k]&& nums[j] != nums[k]){
                        m++;
                    }
                }
            }
           }
           return m;
        // }
        // return 0;
//         int unequalTriplets(vector<int>& nums) {//O(N) and O(N)
//     unordered_map<int,int> freq;
//     for (int x : nums) freq[x]++;

//     int ans = 0;
//     int left = 0;
//     int n = nums.size();

//     for (auto &p : freq) {
//         int cnt = p.second;
//         int right = n - left - cnt;
//         ans += left * cnt * right;
//         left += cnt;
//     }
//     return ans;
// }
    }
};

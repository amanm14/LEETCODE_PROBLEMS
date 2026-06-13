class Solution {
public://o(n) is tc and sc
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>ans;
        ans.insert(ans.begin(),nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        ans.insert(ans.end(),nums.begin(),nums.end());
        return ans;
    }
};

//alternate without function use clean solution 

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2*n);
        for(int i = 0;i<n;++i){
            ans[i] = nums[i];
            ans[i+n] = nums[n-i-1];
        }
        return ans;
    }
};

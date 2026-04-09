class Solution {
public://O(n2logn) is tc and O(n) is s
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            map<int,int> mp;
            
            for(int j = i; j < nums.size(); j++) {
                mp[nums[j]]++;
                int x = mp.size();
                ans += x * x;
            }
        }
        
        return ans;
    }
};

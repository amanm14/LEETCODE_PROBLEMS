class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
// Time Complexity: O(n² log n) can be optimized till O(N)
// Space Complexity: O(n)
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        int s=mp.size();
        mp.clear();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp.size()>=s){
                    //mp.clear();
                    cnt++;
                }
            }
            mp.clear();
        }
        return cnt;
    }
};

class Solution {
public:
// TCO(N2) SC O(1)
    int numIdenticalPairs(vector<int>& nums) {
        
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;


        // unordered_map<int, int> freq;
        // int count=0;
        // for(int num:nums){
        //     count+=freq[num];
        //     freq[num]++;
        // }
        // return count; //O(N) and O(N)
    }
};

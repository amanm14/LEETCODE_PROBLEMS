class Solution {
public: //tc -> O(n*len(nums[i])) and sc is O(1)
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i],cnt=0;
            while(temp>0){
                cnt++;
                temp=temp/10;
            }
            if(cnt%2==0) ans++;
        }
        return ans;
    }
};

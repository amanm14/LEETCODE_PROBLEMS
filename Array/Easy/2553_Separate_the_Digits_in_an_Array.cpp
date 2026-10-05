class Solution {
public://O(1000*10^5==10^8)==this is only 8 digit so O(n) is tc and sc overall
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            vector<int>t;
            while(x>0){
                t.push_back(x%10);
                x=x/10;
            }
            for(int j=t.size()-1;j>=0;j--)
            {
                ans.push_back(t[j]);
            }
        }
        return ans;
    }
};

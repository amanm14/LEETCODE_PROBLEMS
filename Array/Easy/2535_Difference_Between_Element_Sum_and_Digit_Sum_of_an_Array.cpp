class Solution {
public: //O(n*log2000)==O(1) is tc and sc is O(1)
    int differenceOfSum(vector<int>& nums) {
     int sum=0;
     int d=0;

     for(int i=0;i<nums.size();i++)
     {
        sum+=nums[i];
        int c=nums[i];
        // d=0;
        while(c>0)
        {
            int x=c%10;
            d+=x;
            c=c/10;
        }
     } 
     return abs(sum-d);
    }
};

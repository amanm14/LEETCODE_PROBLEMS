class Solution {
public://O(nlogn) is tc and O(1) is sc
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int x=0,i=0;
        int y=0,j=nums.size()-1;;
        while(i<k){
            x+=nums[i++];
            y+=nums[j--];
        }
        return y-x;
    }
};

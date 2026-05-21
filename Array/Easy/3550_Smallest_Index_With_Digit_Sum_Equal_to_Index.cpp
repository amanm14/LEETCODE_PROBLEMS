class Solution {
public://O(n) is tc and O(1) is sc
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            int temp=0;
            while(x>0){
                temp+=x%10;
                x=x/10;
                // cout<<i<<" x "<<x<<" "<<temp<<endl;
            }
            if(i==temp){
                return i;
            }
        }
        return -1;
    }
};

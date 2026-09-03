class Solution {
public://O(n) is tc and sc is O(1)
    int minElement(vector<int>& nums) {
        int mi=INT_MAX;
        int temp=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            temp=nums[i];
            while(temp>0)
            {
                sum+=temp%10;
                temp=temp/10;
            }
            nums[i]=sum;
            mi=min(mi,sum);
        }
        return mi;
    }
};

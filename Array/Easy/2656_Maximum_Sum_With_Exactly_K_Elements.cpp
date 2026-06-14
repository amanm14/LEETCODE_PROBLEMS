class Solution {
public://O(N) is tc and sc
    int maximizeSum(vector<int>& nums, int k) {
        int m=INT_MIN,ans=0;
        for(int i:nums){
            m=max(i,m);
        }
        while(k>0){
            ans=ans+m;
            m=m+1;
            k--;
        }
        return ans;
    }
};

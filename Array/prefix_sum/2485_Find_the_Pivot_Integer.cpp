class Solution {
public://O(N) is tc and O(1) is sc
    int pivotInteger(int n) {
        // int j=n;
        // int i=1,lsum=1,rsum=n;
        // while(i<=j)
        // {
        //     if(i==j&&lsum==rsum) return i;
        //     if(lsum<=rsum)lsum+=++i;
        //     if(rsum<lsum)rsum+=--j;
        // }
        // return -1;

        //This is proper prefixSum approach or bioler code format for prefix sum
        int psum=0;
        int ssum=0;
        int totalsum=0;
        totalsum=(n*(n+1))/2;
        for(int i=1;i<=n;i++)
        {
            psum+=i;
            ssum=totalsum-psum+i;
            if(psum==ssum) return i;
        }
        return -1;
    }
};

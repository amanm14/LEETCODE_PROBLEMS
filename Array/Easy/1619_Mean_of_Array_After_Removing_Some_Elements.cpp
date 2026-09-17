class Solution {
public://O(n*logn) is tc and sc is O(1)
    double trimMean(vector<int>& arr) {
        int zz=arr.size();
        int x=((zz*5/100));
        cout<<x<<" x "<<arr.size()-x<<endl;
        if(arr.size()-x<=0) return -1;
        int ans=0;

        sort(arr.begin(),arr.end());
        int i;
        int n=arr.size()-x;
        for(i=x;i<n;i++)
        {
            cout<<arr[i]<<"  ";
            ans+=arr[i];
        }
        cout<<ans<<endl;
        // cout<<f(172/37)<<endl;
double z=(double)ans/(n-x);
        return z;
    }
};

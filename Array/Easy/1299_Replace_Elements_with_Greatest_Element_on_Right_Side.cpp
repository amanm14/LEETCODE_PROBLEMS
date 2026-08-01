class Solution {
public://O(N) IS TC AND SC IS o(1)
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int greatest=arr[n-1];
        vector<int>ans(n,-1);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>greatest)
            {
                ans[i]=greatest;
                greatest=arr[i];
            }
            else{
                ans[i]=greatest;
            }
        }
        return ans;
    }
};

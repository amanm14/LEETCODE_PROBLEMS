class Solution {
public://O(n^2) and tc is O(1)
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0,ans=0;
        for(int i=0;i<arr1.size();i++)
        {
            cnt=0;
            for(int j=0;j<arr2.size();j++)
            {
                if(abs(arr1[i]-arr2[j])<=d) cnt++; 
            }
            if(cnt==0) ans++;
        }
        return ans;
    }
};

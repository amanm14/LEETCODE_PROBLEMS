class Solution {
public://O(nlogn) is tc and sc is O(1)
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=INT_MIN;
        int p=points[0][0];
        for(int i=1;i<points.size();i++)
        {
            // cout<<points[i][0]<<endl;
            ans=max(ans,abs(points[i][0]-p));
            p=points[i][0];
        }
        return ans;
    }
};

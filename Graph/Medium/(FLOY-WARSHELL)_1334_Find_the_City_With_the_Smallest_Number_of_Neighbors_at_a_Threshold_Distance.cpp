class Solution {
public://O(n^3) is tc ANND o(n^2) IS SC
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++) dis[i][i]=0;

        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dis[i][via]==INT_MAX||dis[via][j]==INT_MAX) continue;
                    dis[i][j]=min((dis[i][via]+dis[via][j]),dis[i][j]);
                }
            }
        }
        int cityno=1;
        int cntcity=INT_MAX;
        for(int city=0;city<n;city++)
        {
            int cnt=0;
            for(int adjcity=0;adjcity<n;adjcity++)
            {
                if(dis[city][adjcity]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntcity){
                cntcity=cnt;
                cityno=city;
            }
        }
        return cityno;
    }
};

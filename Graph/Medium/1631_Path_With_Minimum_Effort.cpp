class Solution {
public://tc is E*log(V) and SC is O(N*M)
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,10e8));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        dis[0][0]=0;
        pq.push({0,{0,0}});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!pq.empty())
        {
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1&&col==m-1) return diff;
            for(int i=0;i<4;i++)
            {
                int nr=row+delr[i];
                int nc=col+delc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    int newDiff=max(diff,abs(heights[row][col]-heights[nr][nc]));
                    if(newDiff<dis[nr][nc]){
                        dis[nr][nc]=newDiff;
                        pq.push({dis[nr][nc],{nr,nc}});
                    }
                } 
            }
        }
        // cout<<"hello"<<endl;
        return 0;
    }
};

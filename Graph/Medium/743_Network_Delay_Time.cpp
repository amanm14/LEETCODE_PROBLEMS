class Solution {
public:
// Time Complexity: O((V + E) log V)

// Space Complexity: O(V + E)
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>>ans(n+1);
        for(int i=0;i<times.size();i++)
        {
            pair<int,int>z={times[i][2],times[i][1]};
            ans[times[i][0]].push_back(z);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        int fans=INT_MIN;
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(d > dis[node])
                continue;
            for(auto it:ans[node]){
                if(d+it.first<dis[it.second])
                {
                    pq.push({(d+it.first),it.second});
                    dis[it.second]=d+it.first;
                }
            }

        }
        // int fans=0;
        for(int i=1;i<dis.size();i++){
            // cout<<it<<" it ";
             if(dis[i]==INT_MAX) return -1;
             fans=max(dis[i],fans);
        }
        return fans;
    }
};

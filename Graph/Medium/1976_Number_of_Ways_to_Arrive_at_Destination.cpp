class Solution {
public://tc is  E*logV and sc is O(V+E)
    int countPaths(int n, vector<vector<int>>& roads) {
        //graph pq ->{dis,nodes}
        vector<vector<pair<int,long long>>>adjL(n);
        for(auto it:roads)
        {
            adjL[it[0]].push_back({it[1],it[2]});
            adjL[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dis(n,LLONG_MAX);
        vector<int>ways(n,0);
        int mod=(int)(1e9+7);
        pq.push({0,0});
        dis[0]=0;
        ways[0]=1;
        while(!pq.empty())
        {
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adjL[node])
            {
                int nNode=it.first; //first of the queue holds dis but adjL first of pair holds node not dist
                int ndist=it.second;
                if((ndist+dist)<dis[nNode])
                {
                    dis[nNode]=dist+ndist;
                    pq.push({dist+ndist,nNode});
                    ways[nNode]=ways[node];
                   
                }
                else if(dist+ndist==dis[nNode]){
                    ways[nNode]=(ways[node]+ways[nNode])%mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         //graph pq ->{dis,nodes}
//         vector<vector<pair<int,int>>>adjL(n);
//         for(auto it:roads)
//         {
//             adjL[it[0]].push_back({it[1],it[2]});
//             adjL[it[1]].push_back({it[0],it[2]});
//         }
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//         vector<int>dis(n,1e9);
//         vector<int>ways(n,0);
//         int mod=(int)(1e9+7);
//         pq.push({0,0});
//         dis[0]=0;
//         ways[0]=1;
//         while(!pq.empty())
//         {
//             int dist=pq.top().first;
//             int node=pq.top().second;
//             pq.pop();
//             for(auto it:adjL[node])
//             {
//                 int nNode=it.first; //first of the queue holds dis but adjL first of pair holds node not dist
//                 int ndist=it.second;
//                 if(ndist+dist<dis[nNode])
//                 {
//                     dis[nNode]=dist+ndist;
//                     pq.push({dist+ndist,nNode});
//                     ways[nNode]=ways[node];
                   
//                 }
//                 else if(dist+ndist==dis[nNode]){
//                     ways[nNode]=(ways[node]+ways[nNode])%mod;
//                 }
//             }
//         }
//         return ways[n-1] % mod;
//     }
// };

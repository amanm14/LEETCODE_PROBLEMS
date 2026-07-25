class Solution {
public://tc is E*logV as  we are not using PQ so logV will not be in tc so tc is O(V=flights.size()) and sc is 


//O(N+E)
// N = n (number of nodes)
// E = flights.size() (number of edges/flights)

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //{stops,nodes,dis}
        vector<int>dis(n,10e8);
        vector<vector<pair<int,int>>>adjL(n);
        for(int i=0;i<flights.size();i++)
        {
            adjL[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adjL[node])
            {
                int newCost=cost+it.second;
                int nNode=it.first;

                if(dis[nNode]>newCost &&stops<=k){
                    dis[nNode]=newCost;
                    q.push({stops+1,{nNode,newCost}});
                }
            }

        }
        if(dis[dst]==10e8) return -1;
        return dis[dst];
    }
};

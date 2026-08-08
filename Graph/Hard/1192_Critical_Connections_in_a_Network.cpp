class Solution {//O(v+E) is tc and sc
    int timer=1;
    private:
        void dfs(int node,int parent,vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges,vector<vector<int>>&adj,vector<int>&vis)
        {
            vis[node]=1;
            low[node]=tin[node]=timer;
            timer++;
            for(auto it:adj[node])
            {
                if(parent==it) continue;
                
                if(vis[it]==0)
                {
                    dfs(it,node,tin,low,bridges,adj,vis);
                    low[node]=min(low[node],low[it]);
                    if(low[it]>tin[node]){
                        bridges.push_back({node,it});
                    }
                }
                else{
                    low[node]=min(low[node],low[it]);
                }
            }
        }
public:
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adjL(n);
        // int n=connections[0].size();
        for(auto it:connections)
        {
            adjL[it[0]].push_back(it[1]);
            adjL[it[1]].push_back(it[0]);
        }
        vector<int>low(n);
        vector<int>tin(n);
        vector<int>vis(n,0);
        vector<vector<int>>bridges;
        dfs(0,-1,tin,low,bridges,adjL,vis);
        
        return bridges;

    }
};

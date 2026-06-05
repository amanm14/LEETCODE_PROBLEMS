class Solution {
public://O(v+e) is tc and sc is O(v)
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(n,0);
        vis[source]=1;
        queue<int>q;
        q.push(source);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(node==destination) return true;
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return false;
    }
};

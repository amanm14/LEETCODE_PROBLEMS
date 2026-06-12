class Solution {
public://O(n+2*E) is tc and O(n) is sc
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),-1);
        queue<int>q;
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i] != -1)
                continue;
            vis[i]=0;
            q.push(i);

        // BFS
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(auto it:graph[node])
                    {
                        if(vis[it]==-1){
                            vis[it]=!vis[node];
                            q.push(it);
                        }
                        else if(vis[it]==vis[node]){
                            return false;
                        }
                    }
                }
        }
                return true;
    }
};

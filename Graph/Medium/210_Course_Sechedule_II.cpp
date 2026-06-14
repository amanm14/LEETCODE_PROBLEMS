class Solution {
public://O(v+e) is tc and  sc
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
    for(auto it:edges){
        adj[it[1]].push_back(it[0]);
    }
    queue<int>q;
    vector<int>indeg(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adj[i])
        {
            indeg[it]++;
        }
    }
    
    for(int i=0;i<indeg.size();i++){
        if(indeg[i]==0) q.push(i);
    }
   vector<int>topo;
         while(!q.empty())
         {
             int x=q.front();
             q.pop();
             topo.push_back(x);
             for(auto it:adj[x])
             {
                 indeg[it]--;
                 if(indeg[it]==0) q.push(it);
             }
         }
         
        if(V==topo.size()) return topo;
        else return {};
    
    }
};

class Solution {
  public://O(v+E) is tc and sc is O(3*V)
  void dfs(int node, stack<int>&st,vector<int>&vis,vector<vector<int>>&edges)
  {
      vis[node]=1;
      for(auto it:edges[node]){
          if(!vis[it]){
              dfs(it,st,vis,edges);
          }
          
      }
      st.push(node);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        stack<int>st;
        vector<int>vis(V,0);
        vector<vector<int>> adj(V);

    for(auto &e : edges){ //build adjecency list first
        adj[e[0]].push_back(e[1]);
    }
        for(int i=0;i<V;i++){
            if(!vis[i])
            {
                dfs(i,st,vis,adj);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            int x=st.top();
            ans.push_back(x);
            st.pop();
        }
        // for(int it:ans) cout<<it<<endl;
        return ans;
    }
};

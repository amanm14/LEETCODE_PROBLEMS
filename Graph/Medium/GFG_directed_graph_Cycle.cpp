class Solution {
  public://O(V+E) is tc and sc
  bool dfs(int node,int n,vector<int>&pathVis,vector<int>&vis,vector<vector<int>> &mat)
  {
      vis[node]=1;
      pathVis[node]=1;
      for(auto it:mat[node]){ //whatever we check and call we call it on --> it not on node or node+1
         
              if(pathVis[it]==1){
                  return true;
              }
              else if(!vis[it]){
                  if(dfs(it,n,pathVis,vis,mat))
                    return true;
              }
              
          }
      
      pathVis[node]=0; //2we are making the path to 0 incase of not getting true so when we get true and path is 1 so it must lie in current path
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adjMat(V);

    for(int i=0;i<edges.size();i++)//also there is no need to create a adjMat coz adj vector itself can be work like adjMat
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjMat[u].push_back(v);
    }
      
    vector<int>pathVis(V,0);
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){//graph can be disconnected so run it on loop of vertices and vis[] that would run on every vertices
        if(!vis[i]) 
            if(dfs(i,V,pathVis,vis,adjMat))return true;
    }    
    
    return false;
    }
};

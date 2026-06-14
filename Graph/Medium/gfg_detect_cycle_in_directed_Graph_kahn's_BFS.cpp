class Solution {
  public://O(V+E) is tc and sc
//   bool dfs(int node,int n,vector<int>&pathVis,vector<int>&vis,vector<vector<int>> &mat)
//   {
//       vis[node]=1;
//       pathVis[node]=1;
//       for(auto it:mat[node]){
         
//               if(pathVis[it]==1){
//                   return true;
//               }
//               else if(!vis[it]){
//                   if(dfs(it,n,pathVis,vis,mat))
//                     return true;
//               }
              
//           }
      
//       pathVis[node]=0;
//       return false;
//   }
    // bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
    //     vector<vector<int>>adjMat(V);

    // for(int i=0;i<edges.size();i++)
    // {
    //     int u = edges[i][0];
    //     int v = edges[i][1];

    //     adjMat[u].push_back(v);
    // }
      
    // vector<int>pathVis(V,0);
    // vector<int>vis(V,0);
    // for(int i=0;i<V;i++){
    //     if(!vis[i]) 
    //         if(dfs(i,V,pathVis,vis,adjMat))return true;
    // }    
    
    // return false;
    // }
     bool isCyclic(int V, vector<vector<int>> &edges) {
         vector<vector<int>>adj(V);
         for(auto it:edges)
             {
                 adj[it[0]].push_back(it[1]);
             }
         
         vector<int>indeg(V,0);
         queue<int>q;
         for(int i=0;i<V;i++)
         {
             for(auto it:adj[i]){
                 indeg[it]++;
             }
         }
         for(int i=0;i<indeg.size();i++){
        if(indeg[i]==0) q.push(i);
    }
        //  vector<int>ans;
        int cnt=0;
         while(!q.empty())
         {
             int x=q.front();
             q.pop();
             cnt++;
             for(auto it:adj[x])
             {
                 indeg[it]--;
                 if(indeg[it]==0) q.push(it);
             }
         }
         
         if(cnt==V) return false;
         return true;
     }
};

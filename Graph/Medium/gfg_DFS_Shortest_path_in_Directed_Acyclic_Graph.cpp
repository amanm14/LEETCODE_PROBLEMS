// User function Template for C++
class Solution {
  public://O(v+e) is tc and sc
  void topo(int node,vector<pair<int,int>>adjL[],int V,stack<int>&st,vector<int>&vis){
     vis[node]=1;
     for(auto it:adjL[node])
          {
              if(!vis[it.first])//coz it adjL[node] store pair in vectro
              {
                  topo(it.first,adjL,V,st,vis);
              }
          }
          st.push(node);
      
      
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        stack<int>st;
        vector<pair<int,int>>adjL[V];
        for(int i=0;i<edges.size();i++)
        {
            adjL[edges[i][0]].push_back({edges[i][1],edges[i][2]});//vertice and weight
            
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                topo(i,adjL,V,st,vis);
            }
        }
        vector<int>ans(V,INT_MAX);
        ans[0]=0;
        while(!st.empty())
        {
            int x=st.top();
            st.pop();
            if(ans[x]!=INT_MAX){
                for(auto it:adjL[x])
                {
                    int V=it.first;
                    int wt=it.second;
                   ans[V]=min(ans[V],ans[x]+wt);
                }
            }
            
        }
        for(int i=0;i<V;i++)
        {
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        }
        return ans;
    }
};

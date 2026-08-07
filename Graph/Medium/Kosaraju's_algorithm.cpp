class Solution{//O(V+E) is tc and sc
private:
    void dfs(vector<int> adj[],int i,vector<int>&vis,stack<int>&st)
{
    vis[i]=1;
    for(auto it:adj[i])
    {
        if(vis[it]==0)
        {
            dfs(adj,it,vis,st);
        }
    }
    st.push(i);
}
void dfs3(int node,vector<int>&vis,vector<int> adjT[])
{
    vis[node]=1;
    for(auto it:adjT[node])
    {
        if(vis[it]==0) dfs3(it,vis,adjT);
    }
}
public:
    int kosaraju(int V, vector<int> adj[]){
      vector<int>vis(V,0);
      vector<int>adjT[V];
      stack<int>st;
      for(int i=0;i<V;i++)
      {
        if(vis[i]==0) dfs(adj,i,vis,st);
      }
      for(int i=0;i<V;i++)
      {
        for(auto it:adj[i])
        {
            adjT[it].push_back(i);
        }
      }
      fill(vis.begin(), vis.end(), 0);
      int scc=0;
      while(!st.empty())
      {
        int node=st.top();
        st.pop();
        if(vis[node]==0){
            scc++;
            dfs3(node,vis,adjT);
        }
      }
      return scc;
    }
};

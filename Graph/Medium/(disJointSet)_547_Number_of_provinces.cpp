class disJointSet{
    // vector<int>rank,parent,size;
    public:
    vector<int>rank,parent,size; //this way we can save 4 Alpha time cinplexity
    disJointSet(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findPar(int node)
    {
        if(node==parent[node]){
            return node;
        }
        else return parent[node]=findPar(parent[node]);
    }
    void unionBysize(int u,int v)
    {
        int ult_pu=findPar(u);
        int ult_pv=findPar(v);
        if(ult_pu==ult_pv) return;
        if(size[ult_pu]<size[ult_pv])
        {
            parent[ult_pu]=ult_pv;
            size[ult_pv]+=size[ult_pu];
        }
        else{
            parent[ult_pv]=ult_pu;
            size[ult_pu]+=size[ult_pv];
        }
    }
    void unionByrank(int u,int v)
    {
        int ult_pu=findPar(u);
        int ult_pv=findPar(v);
        if(ult_pu==ult_pv) return;
        if(rank[ult_pu]<rank[ult_pv])
        {
            parent[ult_pu]=ult_pv;
        }
        else if(rank[ult_pv]<rank[ult_pu]){
            parent[ult_pv]=ult_pu;
        }
        else{
            parent[ult_pv]=ult_pu;
            rank[ult_pu]++;
        }
    }
};
class Solution {
public://If grah is given as AdjLisst then it would be O(N)+O(n+2*E(total degree of graph)) sc is O(1)
    // void dfs(int node,vector<vector<int>>&adj,vector<int>&vis)
    // {
    //     vis[node]=1;
    //      for(auto it:adj[node]){
    //         if(vis[it]==0)
    //         {
    //             dfs(it,adj,vis);
    //         }
    //     }
    // }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int cnt=0;
        int n=isConnected.size();
        // vector<vector<int>> adj(n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //     {
        //         if(isConnected[i][j]==1&&i!=j)
        //         {
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        disJointSet ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i != j && isConnected[i][j] == 1){//o(n^2) OVERALL TC
                    ds.unionBysize(i,j);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            // if(ds.findPar(i)==i) cnt++;//saved 4alpha time complecity
            if(ds.parent[i]==i) cnt++;
        }

        // vector<int>vis(n,0);
        
        // for(int i=0;i<n;i++){
        //     if(vis[i]==0){
        //         cnt++;
        //         dfs(i,adj,vis);
        //     }
        // }

        return cnt;
    }
};

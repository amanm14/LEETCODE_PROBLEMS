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
public://O(n) is tc and sc
    int makeConnected(int n, vector<vector<int>>& connections) {
        disJointSet ds(n);
        int cntExtra=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findPar(u)==ds.findPar(v))
            {
                cntExtra++;
            }
            else
            {
                ds.unionBysize(u,v);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i) cntC++;
        }
        if(cntC-1<=cntExtra) return cntC-1;
        return -1;
    }
};

class disJointSet{
    public://tc O(4*alpha)
    vector<int>par,rank,size;
    disJointSet(int n)
    {
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int findPar(int node)
    {
        if(node==par[node]) return node;
        else return par[node]=findPar(par[node]);
    }
    void UnionBySize(int u,int v)
    {
        int ult_pu=findPar(u);
        int ult_pv=findPar(v);
        if(ult_pu==ult_pv) return;
        else if(size[ult_pu]>size[ult_pv])
        {
            size[ult_pu]+=size[ult_pv];
            par[ult_pv]=ult_pu;
        }
        else
        {
            size[ult_pv]+=size[ult_pu];
            par[ult_pu]=ult_pv;
        }
    }
};
class Solution {
public://O(n) is tc and O(maxRow+maxCol) is sc
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones)
        {
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        disJointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stonesnode;
        for(auto it:stones)
        {
            int nodeRow=it[0];
            int nodeCol=maxRow+it[1]+1;
            ds.UnionBySize(nodeRow,nodeCol);
            stonesnode[nodeRow]=1;
            stonesnode[nodeCol]=1;
        }
        int cnt=0;
        for(auto it:stonesnode)
        {
            if(it.first==ds.findPar(it.first))
            {
                cnt++;
            }
        }
        return stones.size()-cnt;
    }
};

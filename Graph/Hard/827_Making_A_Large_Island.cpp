class disJointSet{
    public://tc O(4*alpha)
    vector<int>par,rank,size;
    disJointSet(int n)
    {
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n;i++) par[i]=i;
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
public://O(N^2) is tc and sc
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disJointSet ds(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int k=0;k<4;k++)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr<0||nr>=n||nc<0||nc>=n)
                    {
                        continue;
                    }
                    if(grid[nr][nc]!=1) continue;
                    int nodeNumber=i*n+j;
                    int adjNodeNumber=nr*n+nc;
                    ds.UnionBySize(nodeNumber,adjNodeNumber);
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int>st;
                for(int k=0;k<4;k++)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr<0||nr>=n||nc<0||nc>=n)
                    {
                        continue;
                    }
                    if(grid[nr][nc]!=1) continue;
                    if(grid[nr][nc]==1)
                    {
                        st.insert(ds.findPar(nr*n+nc));
                    }
                }
                int sizeTotal=0;
                for(auto it:st)
                {
                    sizeTotal+=ds.size[it];
                }
                mx=max(sizeTotal+1,mx);
            }
        }
        for(int cellNo=0;cellNo<n*n;cellNo++)
        {
            mx=max(mx,ds.size[ds.findPar(cellNo)]);
        }
        return mx;
    }
};

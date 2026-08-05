class disJointSet{
    // vector<int>rank,parent,size;
    public:
    vector<int>rank,parent,size; //this wacol we can save 4 Alpha time cinplexity
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
class Solution{
public:
vector<int> numOfIslands(int n, int m, vector<vector<int>>& A) {
    vector<vector<int>> grid(n, vector<int>(m, -1));

    disJointSet ds(n * m);

    vector<int> ans;

    int cc = 0;

    int drow[4] = {0, 1, 0, -1};
    int dcol[4] = {1, 0, -1, 0};

    for (auto &op : A) {
        int row = op[0];
        int col = op[1];

        if (grid[row][col] != -1) {
            ans.push_back(cc);
            continue;
        }

        grid[row][col] = row * m + col;
        cc++;

        for (int dir = 0; dir < 4; dir++) {
            int nrow = row + drow[dir];
            int ncol = col + dcol[dir];
            
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                continue;

            if (grid[nrow][ncol] == -1)
                continue;

            if (ds.findPar(grid[row][col])!= ds.findPar(grid[nrow][ncol]))
            {    
                cc--;
                ds.unionBysize(ds.findPar(grid[row][col]),ds.findPar(grid[nrow][ncol]));
            }
        }

        ans.push_back(cc);
    }

    return ans;
}
};

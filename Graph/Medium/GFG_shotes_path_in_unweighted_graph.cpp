class Solution {
  public://Overall TC and SC is O(V+E)
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>>adjL(V);
        for(int i=0;i<edges.size();i++)
        {
            adjL[edges[i][0]].push_back(edges[i][1]);
            adjL[edges[i][1]].push_back(edges[i][0]);
        }
        // for(int i=0;i<adjL.size();i++)
        // {
        //     cout<<i<<"-> ";
        //     for(int j=0;j<adjL[i].size();j++)
        //     {
        //         cout<<" "<<adjL[i][j]<<" ";  
        //     }
        //     cout<<endl;
            
        // }
        
        queue<pair<int,int>>q;
        vector<int>d(V,INT_MAX);
        d[src]=0;
        q.push({src,0});
        while(!q.empty())
        {
            int f=q.front().first;
            int s=q.front().second;
            
            q.pop();
            for(int i=0;i<adjL[f].size();i++)
            {
                // if(adjL[f][i]==f) continue;
                int x=adjL[f][i];
                if(d[x]==INT_MAX){
                    d[x]=s+1;
                    q.push({x,(s+1)});
                }
                
            }
        }
         return d[dest]==INT_MAX ? -1 : d[dest];
    }
};
// 9
// 10
// 0 1
// 0 3 
// 3 4 
// 4 5 
// 5 6 
// 1 2 
// 2 6 
// 6 7 
// 7 8 
// 6 8 
// 0
// 8

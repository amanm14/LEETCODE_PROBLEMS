class Solution {//O(v+E) is tc and sc
    int timer=1;
    private:
        void dfs(int node,int parent,vector<int>&tin,vector<int>&low,vector<int>adj[],vector<int>&vis,vector<int>&mark)
        {
            vis[node]=1;
            low[node]=tin[node]=timer;
            timer++;
            int child=0;
            for(auto it:adj[node])
            {
                if(parent==it) continue;
                
                if(vis[it]==0)
                {
                    dfs(it,node,tin,low,adj,vis,mark);
                    low[node]=min(low[node],low[it]);
                    if(low[it]>=tin[node]&&parent!=-1){
                        mark[node]=1;
                    }
                    child++;
                }
                else{
                    low[node]=min(low[node],low[it]);
                }
            }
            if(child>1){
                mark[node]=1;
            }
        }
public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
         vector<int>mark(n,0);
         vector<int>low(n);
        vector<int>tin(n);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                dfs(i,-1,tin,low,adj,vis,mark);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

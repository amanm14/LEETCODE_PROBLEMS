class Solution {
public://O(V+E) + O(VlogV) and sc O(V+E)
    // bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<vector<int>>&graph)
    // {
    //     vis[node]=1;
    //     pathVis[node]=1;
    //     for(auto it:graph[node]){
    //         if(!vis[it]){
    //             if(dfs(it,vis,pathVis,graph)) return true;
    //         }
    //         if(pathVis[it]==1) return true;
    //     }
    //     pathVis[node]=0;
    //     return false;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // vector<int>vis(graph.size(),0);
        // vector<int>pathVis(graph.size(),0);
        // for(int i=0;i<graph.size();i++){
        //     if(!vis[i]){
        //         dfs(i,vis,pathVis,graph);
        //     }
        // }
        // vector<int>ans;
        // for(int i=0;i<pathVis.size();i++){
        //     if(pathVis[i]==0){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        vector<vector<int>>adj(graph.size());
        vector<int>indeg(graph.size(),0);
        
         for(int i=0;i<graph.size();i++){
           for(auto it:graph[i]){
                adj[it].push_back(i);
                indeg[i]++;
           }

        }
        // for(int it:indeg) cout<<it<<" -- "<<endl;
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(indeg[i]==0)
                q.push(i);
        }
        vector<int>ans;

        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto it:adj[x]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
            // cout<<x<<endl;
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};

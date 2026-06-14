class Solution {
public://O(V+E) is tc and sc
    bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<vector<int>>&graph)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,graph)) return true;
            }
            if(pathVis[it]==1) return true;
        }
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),0);
        vector<int>pathVis(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,graph);
            }
        }
        vector<int>ans;
        for(int i=0;i<pathVis.size();i++){
            if(pathVis[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

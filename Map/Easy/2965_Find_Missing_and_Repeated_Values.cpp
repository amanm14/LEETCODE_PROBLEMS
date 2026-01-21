class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;//O(N2) is TC and O(N) is SC
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                mp[grid[i][j]]++;
            }
        }
        int c=1,a,b;
        vector<int>ans;
        for(auto i:mp)
        {
            if((i.second)>1) a=(i.first);
            // cout<<b<<" "<<a<<endl;
            // cout<<i.first<<" "<<i.second<<endl;
           
        }
        int n=(grid.size()*grid[0].size());
        // cout<<"n "<<n<<endl;
        for(int i=1;i<=n;i++){
            if(mp.count(i)==0){
                b=i;
                break;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};

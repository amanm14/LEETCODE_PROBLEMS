class Solution {
public: //O(picks) and O(n*colors) is sc
    int winningPlayerCount(int n, vector<vector<int>>& picks) {
        
        vector<unordered_map<int,int>> freq(n);
        vector<bool> counted(n,false);

        int ans = 0;

        for(auto &p : picks){

            int player = p[0];
            int color = p[1];

            if(counted[player]) continue;

            freq[player][color]++;

            if(freq[player][color] > player){
                ans++;
                counted[player] = true;
            }
        }

        return ans;
    }
};

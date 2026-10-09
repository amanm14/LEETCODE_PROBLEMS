// class Solution {
// public:
//     vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
//         int n=grid.size();
//         vector<vector<int>>ans(n-2,vector<int>(n-2));
//         for(int i=0;i<grid.size()-1;i++)
//         {
//             int dr[]={-1,0,1,0};
//             int dc[]={0,-1,0,1};
//             for(int j=0;j<grid[i].size()-1;j++)
//             {
//                 int m=INT_MIN;
//                 for(int i1=0;i1<4;i1++)
//                 {
//                     m=max(m,grid[dr[i]][dc[i]]);
//                 }
//                 // ans[i].push_back(m);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public://outer space O(n^2) is tc and O(n^2) space complexity if space leaving output space that is auxiliary space is O(1)
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                int m = INT_MIN;

                for(int r = i; r < i + 3; r++) {
                    for(int c = j; c < j + 3; c++) {
                        m = max(m, grid[r][c]);
                    }
                }

                ans[i][j] = m;
            }
        }

        return ans;
    }
};

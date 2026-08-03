// class Solution {
// public://O(n*m) is tc and sc
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         int x = 0;
//         int y = 0;
//         int dx = 1;
//         int dy = 0;
//         vector<int> res;

//         for (int i = 0; i < rows * cols; i++) {
//             res.push_back(matrix[y][x]);
//             matrix[y][x] = -101;

//             if (!(0 <= x + dx && x + dx < cols && 0 <= y + dy && y + dy < rows) || matrix[y+dy][x+dx] == -101) {
//                 int temp = dx;
//                 dx = -dy;
//                 dy = temp;
//             }

//             x += dx;
//             y += dy;
//         }

//         return res;
//     }        
// };
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty() || matrix[0].empty()) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while(top <= bottom && left <= right) {
            // Traverse right
            for(int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            // Traverse down
            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            // Traverse left
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // Traverse up
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         // int arr[n];
//         // vector<vector<int>>ans(n,vector<int>(n));
//         // int k=0;
//         // for(int i=n-1;i>=0;i--)
//         // {
//         //     for(int j=0;j<n;j++)
//         //     {
//         //         ans[j][i]=matrix[k][j];
//         //     }
//         //     k++;
//         // }
//         // for(int i=0;i<n;i++)
//         // {
//         //     for(int j=0;j<n;j++)
//         //     {
//         //         matrix[i][j]=ans[i][j];
//         //     }
//         // }
//         // return ;
//         // (i,j)→(j,n−1−i)→(n−1−i,n−1−j)→(n−1−j,i)
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 int x=matrix[j][n-1-i];
//                 int y=matrix[n−1−i][n−1−j];
//                 int z=matrix[n-1-j][i];
//                 matrix[n−1−i][n−1−j]=matrix[i][j];
//                 matrix[n-1-j][i]=y;
//                 matrix[j][n-1-i]=z;
//                 matrix[i][j]=x;
//             }
//         }
//         return;
//     }
// };
class Solution {//4 way rotation approach
public://O(n*n) is time and O(1) is sc
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Iterate over layers (i) and elements in each layer (j)
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                // Perform the cyclic swap:
                // Save top-left
                int temp = matrix[i][j];
                
                // Move bottom-left to top-left
                matrix[i][j] = matrix[n - 1 - j][i];
                
                // Move bottom-right to bottom-left
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                
                // Move top-right to bottom-right
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                
                // Move saved top-left to top-right
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};

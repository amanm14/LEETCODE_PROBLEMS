class Solution {
public://O(n2) is tc and O(1) is sc
        static const vector<vector<int>>& flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row : A) {
            reverse(row.begin(), row.end());
            for (auto& v : row) v ^= 1;
        }
        return A;
    }
};

// | Type                               | Complexity | Explanation                            |
// | ---------------------------------- | ---------- | -------------------------------------- |
// | **Time Complexity**                | O(m × n)   | Each cell visited once in spiral order |
// | **Auxiliary Space**                | O(1)       | Only pointers and counters used        |
// | **Total Space (including output)** | O(m × n)   | For storing the matrix                 |

class Solution {
public:
   vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> z(m, vector<int>(n, -1));

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (head != nullptr && top <= bottom && left <= right) {
        // }Move → (left to right)
        for (int j = left; j <= right && head; j++) {
            z[top][j] = head->val;
            head = head->next;
        }
        top++;

        // Move ↓ (top to bottom)
        for (int i = top; i <= bottom && head; i++) {
            z[i][right] = head->val;
            head = head->next;
        }
        right--;

        // Move ← (right to left)
        for (int j = right; j >= left && head; j--) {
            z[bottom][j] = head->val;
            head = head->next;
        }
        bottom--;

        // Move ↑ (bottom to top)
        for (int i = bottom; i >= top && head; i--) {
            z[i][left] = head->val;
            head = head->next;
        }
        left++;
    }

    return z;
}
};

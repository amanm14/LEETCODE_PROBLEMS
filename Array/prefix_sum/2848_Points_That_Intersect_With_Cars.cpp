class Solution {
public://O(n) is tc and sc is O(1)
    int numberOfPoints(vector<vector<int>>& nums) {
        int line[102] = {0};
        int points_on_line = 0;

        for (int i = 0; i < nums.size(); i++) {
            int s = nums[i][0];
            int e = nums[i][1];
            line[s] += 1;
            line[e + 1] -= 1;
        }

        for (int i = 1; i < 102; i++) {
            line[i] += line[i - 1];
            if (line[i] != 0) {
                points_on_line += 1;
            }
        }

        return points_on_line;
    }
};

// i th position will store the i-1 index element either it can be 0 or 1 so from the start we can run this and it will keep adding one till end because we are marking -1 to the end+1 pointing it to be mark 1 at one extra position so we can mark 1 till 1 to -1 and keep checking whether its 1 or not if 1 then we can take that in count and later return count as our answer 

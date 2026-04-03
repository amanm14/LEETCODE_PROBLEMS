class Solution {
public://O(n)  is sc and tc
    int firstUniqueEven(vector<int>& nums) {
        map<int, int> M;

        for (int num : nums) 
            M[num]++;

        for (int num : nums) {
            if (num % 2 == 0 && M[num] == 1)
                return num;
        }

        return -1;
    }
};

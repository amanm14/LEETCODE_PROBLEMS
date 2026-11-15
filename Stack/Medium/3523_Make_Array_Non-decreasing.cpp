class Solution {
public://O(n) is tc and sc is O(1)
    int maximumPossibleSize(vector<int>& nums) {

        int size = 0, prev = -1;

        for(auto num : nums) {
            if(num >= prev) {
                prev = num;
                size++;
            }
        }

        return size;
    }
};

// ?O(nlogn) tc and sc is O(N)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b])
                return a > b;        // higher value first
            return freq[a] < freq[b]; // lower frequency first
        });

        return nums;
    }
};

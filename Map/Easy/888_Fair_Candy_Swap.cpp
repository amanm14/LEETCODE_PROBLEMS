class Solution {
public: //o(n+m) TC AND SC
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {

        int aliceSum = 0, bobSum = 0;
        for(int x : aliceSizes) aliceSum += x;
        for(int x : bobSizes) bobSum += x;

        int diff = (bobSum - aliceSum) / 2;

        unordered_map<int, int> mp;
        for(int b : bobSizes) mp[b]++;

        for(int a : aliceSizes) {
            int b = a + diff;
            if(mp[b] > 0) {
                return {a, b};
            }
        }
        return {};
    }
};

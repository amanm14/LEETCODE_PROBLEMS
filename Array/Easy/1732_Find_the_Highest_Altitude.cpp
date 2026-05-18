class Solution {
public://O(n) is tc and O(1) is sc
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int max = 0;
        int prev = 0;
        for(int i = 0; i<n; i++){
            prev += gain[i];
            if(prev > max){
                max = prev;
            }
        }
        return max;
    }
};

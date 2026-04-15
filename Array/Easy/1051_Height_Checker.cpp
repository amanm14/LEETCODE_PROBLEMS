class Solution {
public://O(Nlogn) is tc and O(N) is sc
    int heightChecker(vector<int>& heights) {
        vector<int>v(heights);
        int cnt=0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<v.size();i++){
            if(heights[i]!=v[i]){
                cnt++;
            }
        }
        return cnt;
    }
};

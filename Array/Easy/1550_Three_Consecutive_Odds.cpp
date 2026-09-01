class Solution {
public://O(n) is tc and O(1) is sc
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            cnt=0;
            while(i<arr.size()&&arr[i]%2!=0)
            {
                cnt++;
                i++;
            }
            if(cnt>=3) return true;
        }
        return false;
    }
};

class Solution {
public://O(n^2) is tc and sc is O(1) but we ccan make it to O(Nlogn) tc and sc O(N)  we can store starts in vector and sort and then check for each start how many eleements are there in start which are less than given pair end the count owuld be answers
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size(),cnt=0;
        if(n<2) return 0;

        for(int i=0;i<n;i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            for(int j=i+1;j<n;j++)
            {
                if(x>intervals[j][1]) continue;
                // if(intervals[j][1]<=intervals[j][0]) continue;
                if(intervals[j][0]<=y) cnt++;
            }
        }
        return cnt;
    }
};

/*class Solution {
public:
    int f(vector<vector<int>>&mat,int n,int target,int curr)
    {
        //set<int>st()
        if(n==0)
        {
            return abs(curr-target);
        }
        int b=INT_MAX;
        for(int i:mat[n-1])
        {
            b=min(b,f(mat,n-1,target,i+curr));
        }
        return b;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        return f(mat,mat.size(),target,0);
    }
};
class Solution {//TLE
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        set<int> dp = {0};   // sums reachable using 0 rows so far

        for (auto& row : mat)
        {
            set<int> new_dp;
            for (int s : dp)
            {
                for (int val : row)
                {
                    new_dp.insert(s + val);
                }
            }
            dp = new_dp;      // move to next row's reachable sums
        }

        int best = INT_MAX;
        for (int s : dp)
        {
            best = min(best, abs(s - target));
        }
        return best;
    }
};*/
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        unordered_set<int> dp;
        dp.insert(0);

        //int cap = 2*target;   // sums beyond this are never useful

        for (auto& row : mat)
        {
            unordered_set<int> new_dp;
            for (int s : dp)
            {
                for (int val : row)
                {
                    int ns = s + val;
                               // prune here, not after
                        new_dp.insert(ns);
                }
            }
            dp = move(new_dp);                  // avoid a copy
        }

        int best = INT_MAX;
        for (int s : dp)
        {
            best = min(best, abs(s - target));
        }
        return best;
    }
};

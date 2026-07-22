class Solution {
public://O(2^9) is tc and O(A*k) is sc a is size of rows of ans and k is size of columns k can be 1 to 9
    void dfs(int idx,vector<vector<int>>&ans,vector<int>temp,int k, int t)
    {
        if(t==0&&k==0){
            ans.push_back(temp);
            return ;
        }
        if(t<=0||k<=0){
            return;
        }
        // if(t>0&&k==0) return ;
        // if(temp.size()>k) return;
        cout<<" t "<<t<<" "<<temp.size()<<endl;
        for(int i=idx;i<=9;i++)
        {
                temp.push_back(i);
                // t=t-i;
                // k--;
                dfs(i+1,ans,temp,k-1,t-i);
                temp.pop_back();
                // t=t+i;
                // k++;
            // return;
        }   
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        if(n<k) return ans;
        dfs(1,ans,temp,k,n);
        return ans;
    }
};

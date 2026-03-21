class Solution {
public://O(n) is sc and tc
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int idx=0;
        for(int i=1;i<=n;i++)
        {
            if(idx<target.size()){
                int x=target[idx];
                if(i==x){
                    idx++;
                    ans.push_back("Push");
                }
                else{
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
            }
            
        }
        return ans;
    }
};

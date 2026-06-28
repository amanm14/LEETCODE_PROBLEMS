class Solution {
public://O(n^2) is tc and O(n) is sc
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        for(int i=0;i<boxes.length();i++)
        {
            int z=i;
            int f=0;
            int r=boxes.length()-1;
            int cnt=0;
            while(z>f)
            {
                if(boxes[f]=='1') cnt+=(i-f);
                f++;

            }
            while(r>z)
            {
                if(boxes[r]=='1') cnt+=r-i;
                r--;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

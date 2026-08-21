class Solution {
public://O(n^3) is tc and sc is O(1)
    int sumOddLengthSubarrays(vector<int>& arr) {
        int cnt=0;
        vector<int>temp;
        for(int i=0;i<arr.size();i++)
        {
            temp.clear();
            // cout<<temp.size()<<endl;
            for(int j=i;j<arr.size();j++)
            {
                temp.push_back(arr[j]);
                if(temp.size()%2!=0)
                {
                    // cout<<temp.size()<<endl;
                    for(int ii:temp) cnt+=ii;
                } 
            }
        }
        return cnt;
    }
};

// simple formula can solve this in O(N) using --> int odd = (left * right + 1) / 2;
// for(int i = 0; i < n; i++)
//         {
//             int left = i + 1;
//             int right = n - i;

//             int odd = (left * right + 1) / 2;

//             ans += arr[i] * odd;
//         }





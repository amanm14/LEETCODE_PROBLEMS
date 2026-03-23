class Solution {
public://O(N) is sc and tc
//     int findShortestSubArray(vector<int>& nums) {
//         map<int,int>mp;
//         for(int i=0;i<nums.size();i++)
//         {
//             mp[nums[i]]++;

//         }
//         int m=0,f=0;
//         for(auto i:mp){
//             if(i.second>m){
//                 m=i.second; f=i.first;
//             }
//         }
//         int size=0;
//         bool flag=false;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==f&&m>0||flag==true&&m>0){
//                 size++;
//                 flag=true;
//                 if(nums[i]==f)m--;
//                 cout<<"m "<<m<<endl;
//             }
//         }
//         return size;
//     }
    int findShortestSubArray(vector<int>& A) {
        unordered_map<int, int> count, first;
        int res = 0, degree = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (first.count(A[i]) == 0) first[A[i]] = i;
            if (++count[A[i]] > degree) {
                degree = count[A[i]];
                res = i - first[A[i]] + 1;
            } else if (count[A[i]] == degree)
                res = min(res, i - first[A[i]] + 1);
        }
        return res;
    }
};

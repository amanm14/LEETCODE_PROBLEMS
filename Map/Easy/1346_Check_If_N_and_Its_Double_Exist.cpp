class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        //O(N2) tc and O(1) sc

        //int j=arr.size()-1;
        // int i=0;
        // for(int i1=0;i1<arr.size();i1++){
        //     i=i1;
        //     j=arr.size()-1;
        //     while(i<j){
        //         if(arr[i]==2*arr[j]){
        //             // cout<<"h"<<endl;
        //             return 1;
        //         }
        //         else  if(2*arr[i]==arr[j]){
        //             return 1;
        //         }
        //         j--;
        //     }
        // }
        //O(nlogn) is tc and O(n) sc
        map<int,int>mp;
        for(auto it:arr) mp[it]++;
        for(auto i:arr){
            if (i == 0 && mp[0] < 2) continue;
            if(mp[2*i]>0) return 1;
        }
        return 0;
    }
};

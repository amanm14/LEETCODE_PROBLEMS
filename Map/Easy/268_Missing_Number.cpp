//O(n)->TC
//O(n)->SC kind of  brute force 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>up;
        for(int i=0;i<n;i++){
            up[nums[i]]=1;//map search for the keys not the values 
        }
        for(int i=0;i<=n;i++){
            if(up.find(i)==up.end()){
                return i;
            } 
        }
        return -1;

    }
};

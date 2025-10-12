// .find() finds the key, not the value
//: map — values can be duplicates, but keys cannot. TC nd SC are O(nlogn) nd O(n) we can use unordered set to reduce its complexity to O(k) or Unordered_map to reduce to O(n) in average case
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mp;
        bool ans=false;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                if(abs(mp[nums[i]]-i)<=k) ans=true;
                else{
                    //  ans=false;
                    mp[nums[i]]=i;
                     
                }
                
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};

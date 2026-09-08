class Solution {
public://O(nlogn) is tc and sc is O(n)
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        vector<vector<int>>ans;
        map<int,int>mp;
        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i]]++;
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(mp[nums1[i]]>0){
                continue;
            }
            else{
                temp.push_back(nums1[i]);
                mp[nums1[i]]++;
            }
        }
        ans.push_back(temp);
        temp.clear();
        mp.clear();
        // for(int i=0;i<temp.size();i++) mp
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(mp[nums2[i]]>0){
                continue;
            }
            else{
                temp.push_back(nums2[i]);
                mp[nums2[i]]++;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

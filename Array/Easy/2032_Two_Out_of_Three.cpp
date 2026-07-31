class Solution {
public://O(n) is tc and O(1) is sc
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>ans;
        // int n=max(nums.size(),max(nums2.size(),nums.size());
        vector<int>check(999,0);
        for(int i=0;i<nums1.size();i++)
        {
            if(check[nums1[i]]!=1)check[nums1[i]]=1;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(check[nums2[i]]==1){
                ans.push_back(nums2[i]);
                check[nums2[i]]=2;
            }
            else if(check[nums2[i]]!=2) check[nums2[i]]=3;
        }
        for(int i=0;i<nums3.size();i++)
        {
            if(check[nums3[i]]==1||check[nums3[i]]==3){
                ans.push_back(nums3[i]);
                 check[nums3[i]] = 2;  
            }
        }
        // set<int>st;//as it is taking O(n*logk) time comlaexity and O(n) space
        // for(auto it:ans) st.insert(it);
        // ans.clear();
        // for(auto it:st) ans.push_back(it);
        return ans;
    }
};

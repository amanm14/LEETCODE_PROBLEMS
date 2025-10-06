// TC-> O(n) SC->O(1) Its stack qus i solved without it 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                bool flag=0;
                if(nums1[i]==nums2[j]){
                    
                    while(flag==0&&j<nums2.size()){
                        if(nums1[i]<nums2[j]){
                            nums1[i]=nums2[j];
                            flag=1;
                        }
                        j++;
                    }
                    if(flag==0) nums1[i]=-1;
                }
            }
        }
        return nums1;
    }

};

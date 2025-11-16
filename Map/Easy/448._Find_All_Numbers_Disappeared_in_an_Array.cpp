class Solution {
public:
// tc O(nlogn) sc-O(n)
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int no=1;
        vector<int>ans;
        map<int,int>mp;
        set<int>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        for(int i:st){
            cout<<no<<endl;
           if(no!=i){
                int temp=i;
                if(no>temp){
                 ans.push_back(no);
                 temp++;
                }
                while(no<i){
                    ans.push_back(no);
                    no++;
                }
           }
           if(i==no){
            no++;
            continue;
            
           }
           
        }
        while(no<=nums.size()){
                ans.push_back(no);
                no++;
        }
        return ans;
    }

};

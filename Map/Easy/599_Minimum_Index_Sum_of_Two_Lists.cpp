class Solution {
public: //O(N) TC nd SC
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string, int> mpp;
        for(int i= 0; i<list1.size();i++){
            mpp[list1[i]]= i;
        }
        int minSum = INT_MAX;
        vector <string> res; 
        for(int i =0; i<list2.size(); i++){
            if(mpp.find(list2[i]) != mpp.end()){
                int sum = i + mpp[list2[i]];
                if(sum < minSum){
                    res.clear();
                    res.push_back(list2[i]);
                    minSum = sum;
                }
                else if(sum == minSum){
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};

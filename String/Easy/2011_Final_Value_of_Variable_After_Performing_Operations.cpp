class Solution {
public:///O(n) is tx and sc is O(1)
    int finalValueAfterOperations(vector<string>& operations) {
        int cnt=0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="--X"){
                cnt-=1;
            }
            else if(operations[i]=="X--"){
                cnt-=1;
            }
            else if(operations[i]=="X++"){
                cnt+=1;
            }
            else cnt+=1;
        }
        return cnt;
    }
};

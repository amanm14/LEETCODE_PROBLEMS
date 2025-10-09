// | i | prices[i] | stack (stores indices) | Action                                      | prices after step |
// | - | --------- | ---------------------- | ------------------------------------------- | ----------------- |
// | 0 | 8         | []                     | push(0)                                     | [8,4,6,2,3]       |
// | 1 | 4         | [0]                    | 8 ≥ 4 → pop(0), prices[0]=8−4=4, push(1)    | [4,4,6,2,3]       |
// | 2 | 6         | [1]                    | 4 ≥ 6 ❌ → push(2)                           | [4,4,6,2,3]       |
// | 3 | 2         | [1,2]                  | 6≥2 pop(2):6−2=4, 4≥2 pop(1):4−2=2, push(3) | [4,2,4,2,3]       |
// | 4 | 3         | [3]                    | 2≥3 ❌ → push(4)                             | [4,2,4,2,3]       |
// O(n) ->TC and SC
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {//now slve it in the O(n)
        stack<int>st;
        int n=prices.size();
        for(int i=0;i<n;i++){
            // for(int j=i+1;j<prices.size();j++){//O(n2) TC soln
            //     if(prices[i]>=prices[j]){
            //         prices[i]=prices[i]-prices[j];
            //         break;
            //     }
            // }
            // st.push(prices[i]);
           while(!st.empty()&&prices[st.top()]>=prices[i]){
                int idx=st.top();
                st.pop();
                prices[idx]-=prices[i];
           }
           st.push(i);
        }
        return prices;
    }
};

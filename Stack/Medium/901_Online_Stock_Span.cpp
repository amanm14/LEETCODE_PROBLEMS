// class StockSpanner {
// public:
// 1st call → 1 comparison
// 2nd call → 2 comparisons
// 3rd call → 3 comparisons
// ...
// Nth call → N comparisons 
// O(n^2) is tc and o(n) is the sc 
//     vector<int>ans;
//     StockSpanner(){
        
//     }
    
//     int next(int price) {
//         int cnt=0;
//         if(ans.size()==0){
//             ans.push_back(price);
//             cnt++;
//         }
//         else{ 
//             ans.push_back(price);
//             for(int it=0;it<ans.size();it++){
//                 if(ans[it]<=price) cnt++;
//                 else cnt=0;
                
//             }
//         }
//         return cnt;
//     }
// };
class StockSpanner {
public://O(n) is tc and sc
    vector<int>ans;
    stack<int>st;//sill store indexes of previous greater element
    StockSpanner(){
        
    }
    
    int next(int price) {

        ans.push_back(price);
        int i=ans.size()-1;

        while(!st.empty()&& ans[st.top()]<=price){
            st.pop();
        }

        int pgi;
        if(st.empty()) pgi=-1;//because we want to return 1 when at idx zero is only element in the ans, otherwise it would return 0
        else pgi=st.top();
        
        st.push(i);

        return i-pgi;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

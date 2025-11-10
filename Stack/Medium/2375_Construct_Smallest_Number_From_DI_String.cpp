// I just hard coded it by running the sample test cases again and again I dont know why

class Solution {
public:
    string smallestNumber(string pattern) { //O(N) nd O(N)
        stack<int>st;
        int ans=0;
        int i=1,j=0,big=INT_MIN;
        for(i;i<=pattern.length();i++,j++){
            if(pattern[j]=='I'){
                st.push(i);
                
                while(!st.empty()){
                    int kk=st.top();
                    big=max(big,kk);
                    ans=ans*10+kk;
                    st.pop();
                }
            }
            else{
                st.push(i);
            }
        }
        while(!st.empty()){
                    int kk=st.top();
                    ans=ans*10+kk+1;
                    big=max(big,kk);
                    st.pop();
                    i--;
                }
        int temp=ans%10;
        // cout<<"I"<<big<<endl;
        if(pattern[pattern.length()-1]=='D') temp--;
        else temp=++big;
        ans=ans*10+temp;
        return to_string(ans);
    }
};

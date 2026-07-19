class Solution {
public://O(N) is tc and sc
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>st;
        int n=heights.size();
        int ans=INT_MIN,fans=0;
        int idx=0,height,right=0,left=0,width=0;
        // st.push(0);
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[i]<heights[st.top()]){
                idx=st.top();
                st.pop();
                height=heights[idx];
                right=i-1;
                if(st.empty()) left=0;
                else left=st.top()+1;
                width=right-left+1;
                ans=max(ans,height*width);
            }
            st.push(i);

    //   idx = stack.top()
    //   pop()

    //   height = heights[idx]

    //   right = n - 1

    //   if stack is empty
    //         left = 0
    //   else
    //         left = stack.top() + 1

    //   width = right - left + 1

    //   answer = max(answer, height * width)
    //   
      }
       while(!st.empty()){
                idx=st.top();
                st.pop();
                height=heights[idx];
                right=n-1;
                if(st.empty()) left=0;
                else left=st.top()+1;
                width=right-left+1;
                ans=max(ans,height*width);
            }
      return ans;
    }
};

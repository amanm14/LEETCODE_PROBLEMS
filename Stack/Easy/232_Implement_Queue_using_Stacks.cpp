class MyQueue {
    // O(N) tc and sc
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // if(!st.empty()){
        //     int x=st1.top();
        //     st2.push(x);
        // }
        st2.push(x);
    }
    
    int pop(){
        int x;
            int t;
            while(!st2.empty()){
                t=st2.top();
                st1.push(t);
                st2.pop();
            }
            st1.pop();
            x=t;
            while(!st1.empty()){
                t=st1.top();
                st2.push(t);
                st1.pop();
            }
            
        
        return x;
    }
    
    int peek() {
        int x;
            int t;
            while(!st2.empty()){
                t=st2.top();
                st1.push(t);
                st2.pop();
            }
            x=t;
            while(!st1.empty()){
                t=st1.top();
                st2.push(t);
                st1.pop();
            }
        
        
        return x;
    }
    
    bool empty() {
        if(st1.empty()&&st2.empty()) return true;
        else return false;
    }
};

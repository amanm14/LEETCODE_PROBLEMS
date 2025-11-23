class CustomStack {
    vector<int>ak;
    int size=0,ms;
public:
    CustomStack(int maxSize) {
        ms=maxSize;
    }
    
    void push(int x) {
        if(size<ms)
        {
        ak.push_back(x);
        size++;
        }
    }
    int pop() {
        if(ak.size()>0)
        {
        int n=ak.back();
        ak.pop_back();
        size--;
        return n;
        }
        return -1;
    }
    void increment(int k, int val) {
        for(int i=0;i<k&&i<ak.size();i++)
        {
            ak[i]+=val;
        }
    }
};

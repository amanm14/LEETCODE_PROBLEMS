class KthLargest {
public:

    // The general form of a priority queue is:
// priority_queue< typename T, typename Container, typename Compare >
// Part	Meaning
// T	Type of elements stored (int here)
// Container	The underlying container used to store the elements (by default vector<T>)
// Compare	Comparison function used to order the elements (less = max-heap, greater = min-heap). Here we are prioritizing smaller elements over greater that is, 1 is prioritized over 2, so it comes at the top

    priority_queue<int,vector<int>,greater<int>>pq;
    int size;

    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};

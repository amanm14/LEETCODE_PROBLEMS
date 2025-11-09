class Solution { //O(N2) sc o(N)
public:
    bool isSort(vector<int>& t) {

        for (int i = 0; i < t.size() - 1; i++) {
            if (t[i] > t[i + 1])
                return false;
        }

        return true;
    }
    
    int minimumPairRemoval(vector<int>& nums) {
        int operation = 0;

        while (!isSort(nums)) 
        {
            int minSum = INT_MAX, ind = -1;
            
            for (int i = 0; i < nums.size() - 1; i++) 
            {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    ind = i;
                    minSum = sum;
                }
            }

            nums[ind] += nums[ind + 1];
            nums.erase(nums.begin() + (ind + 1));

            operation += 1;
        }

        return operation;
    }
};

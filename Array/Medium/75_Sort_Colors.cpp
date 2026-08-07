class Solution {
public:
    void sortColors(vector<int>& nums) {
    int n=nums.size();
    // int a=0,b=0,c=0,i=0;
    // while(i<n)
    // {
    //     if(nums[i]==0)
    //     {
    //         swap(nums[i],nums[a]);
    //         a++;
    //     }
    //     i++;
    // }
    // // cout<<"a "<<a;
    // i=a;
    // while(i<n)
    // {
    //     if(nums[i]==1)
    //     {
    //         swap(nums[i],nums[a]);
    //         a++;
    //     }
    //     i++;
    // }
    // return;

    int i=0,j=n-1,mid=0;
    while(mid<=j)
    {
        if(nums[mid]==1) mid++;
        else if(nums[mid]==2)
        {
            swap(nums[mid],nums[j]);
            j--;

        }
        else{
            swap(nums[mid],nums[i]);
            i++;
            mid++;
        }
    }
    }
};

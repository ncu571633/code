 Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int product = nums[0], nproduct = nums[0];
        int ret = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int temp = product;
            product = max(nums[i], product * nums[i]);
            product = max(product, nproduct * nums[i]);
            nproduct = min(nums[i], nproduct * nums[i]);
            nproduct = min(nproduct, temp * nums[i]);
            ret = max(product, ret);
        }
        return ret;
    }
};

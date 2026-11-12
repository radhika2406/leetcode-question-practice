/*152 MAXIMUM PRODUCT SUBARRAY
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

​​​​​​​Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product=nums[0];
        int min_product=nums[0];
        int product=nums[0];
        for(int i=1;i<nums.size();++i){
            if(nums[i]<0){
                swap(max_product,min_product);
            }
            max_product=max(nums[i],max_product*nums[i]);
            min_product=min(nums[i],min_product*nums[i]);

            product=max(max_product,product);
        }
        return product;
    }
};
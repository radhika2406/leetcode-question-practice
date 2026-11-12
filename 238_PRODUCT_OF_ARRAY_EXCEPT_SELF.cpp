/*238 PRODUCT OF ARRAY EXCEPT SELF
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //complexity O(n^2)
        vector<int> product_array(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for (int j=0;j<nums.size();j++){
                if(i==j){
                    continue;
                }
                product_array[i]*=nums[j];
            }
        }
        return product_array;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //complexity O(n)
        vector<int> product_array(nums.size(),1);
        int prefix_array = 1;
        for (int i = 0; i < nums.size(); i++) {
            product_array[i] = prefix_array;
            prefix_array *= nums[i];
        }
        int suffix_array = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            product_array[i] *= suffix_array;
            suffix_array *= nums[i];
        }
        return product_array;
    }
};
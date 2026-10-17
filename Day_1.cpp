/*1. TWO SUM
You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                if(nums[i]+nums[j]==target)
                {
                    return{i,j};
                }
                else
                {
                    continue;
                }
            }
        }
        return{};
    }
};

/*242. VALID ANAGRAM

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return (s==t);
    }
};

/*217 CONTAINS DUPLICATE
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            int num_freq=freq[nums[i]]++;
            if(num_freq>=1)
            {
                return true;
                break;
            }
        }
        return false;
    }
};

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

/*53 MAXIMUM SUBARRAY
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN, sum=0;
        for(int i=0;i<nums.size();i++){
            sum=max(nums[i],sum+nums[i]);
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};

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

/*153 FIND MINIMUM IN ROTATED SORTED ARRAY
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_num=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min_num){
                min_num=nums[i];
            }
        }
        return min_num;
    }
};

/*33 SEARCH IN ROTATED SORTED ARRAY
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int target_index=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                target_index=i;
            }
        }
        return target_index;
    }
};

/**/
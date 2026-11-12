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
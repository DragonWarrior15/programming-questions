/*
https://leetcode.com/problems/single-number/
Problem 136

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

/*a number xor with itself returns 0, and 0 xor anything is the number itself*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

// https://leetcode.com/problems/maximum-subarray/
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, max_sum = 0;
        for(int x: nums){
            // try to add this into the current running max sum
            max_sum += x;
            // if max_sum becomes negative, discard everything and reset
            // max_sum because removing a negative from the sum will
            // only increase the sums value
            max_sum = max(max_sum, x);
            // reset the answer if its bigger
            ans = max(ans, max_sum);
        }
        return ans;
    }
};
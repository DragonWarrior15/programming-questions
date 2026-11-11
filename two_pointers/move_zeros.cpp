/*
https://leetcode.com/problems/move-zeroes/description/

283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining
the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_index = -1, num_index = -1, i = 0;
        // get the index of zero
        while(i < nums.size()){
            if(nums[i] == 0){
                zero_index = i;
                break;
            }
            i++;
        }
        if(zero_index != -1){
            // get the index of non zero
            i = zero_index + 1;
            while(i < nums.size()){
                if(nums[i] != 0){
                    num_index = i;
                    break;
                }
                i++;
            }
            if(num_index != -1 & zero_index < num_index){
                // swap the two
                nums[zero_index] = nums[num_index];
                nums[num_index] = 0;
                moveZeroes(nums);
            }
        }
    }
};
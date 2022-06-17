/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
80. Remove Duplicates from Sorted Array II

Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,0,1,1,1,1,2,3,3],
Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
It doesn't matter what values are set beyond the returned length.

Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = nums.size(), curr_idx = 0, next_idx = 1, steps;
        while(next_idx < ans){
            if(nums[curr_idx] != nums[next_idx]){
                // different numbers, change curr and next idx
                curr_idx++; next_idx++;
            }else{
                // numbers are same, keep moving next idx till the value changes
                while(next_idx < ans){
                    if(nums[next_idx] == nums[curr_idx]){
                        next_idx++;
                    }else{
                        // check if the number of duplicates > 2
                        if(next_idx - curr_idx > 2){
                            // we need to shift everything by some steps
                            steps = next_idx - curr_idx - 2;
                            for(int i = next_idx; i < ans; i++){
                                nums[curr_idx + 2 + (i - next_idx)] = nums[i];
                            }
                            // reduce the length of final answer
                            ans -= (next_idx - curr_idx - 2);
                        }
                        // shifting complete, change the curr and next idx
                        curr_idx += 2; next_idx = curr_idx + 1;
                        // get out of loop
                        break;
                    }
                }
                if(next_idx - curr_idx > 2){
                    // reduce the length of final answer
                    ans -= (next_idx - curr_idx - 2);
                }
            }
        }
        return ans;
    }
};

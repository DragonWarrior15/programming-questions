/*
https://leetcode.com/problems/jump-game/

Given an array of non-negative integers nums, you are initially positioned at 
the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. 
Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
    1 <= nums.length <= 3 * 10^4
    0 <= nums[i] <= 10^5
*/

/*
One possible way to solve this is to use recursion
we can have an optional index variable in the canJump definition which will
denote the starting index, and we will recursively call the canJump function
after incrementing the index value.
Answer at current index = Or of all boolean answers in range (current index + 1,
current index + nums[current index])

we can add memoization on top of this to improve the solution further. but
even this will not pass the question

the follwing solution builds the answer from right to left. At the last index,
the answer is always true. for the index just before that, answer is true if
the value at that index is non zero.
for any index in between, solution is Or of all answers at indices in the range
index + 1 to index + nums[index]. We can cleverly check for the or, if any
solution in that range is true, the answer at index must also be true.
Finally, after traversing the entire array, we reach the start and return
the answers[0] as final answer
*/

class Solution {
public:
    // start checking in the reverse order
    bool canJump(vector<int>& nums) {
        // initialization of memoization
        vector<bool> idxAns;
        for(int i = 0; i < nums.size(); i++){
            idxAns.push_back(false);
        }
        // already at the last index
        if(nums.size() == 1){
            idxAns[0] = true;
            return true;
        }
        if(nums.size() == 2){
            // value at idx 0 >= 1 for a jump
            if(nums[0] == 0){
                return false;
            }else{
                return true;
            }
        }
        // start checking in the reverse order of idxs
        idxAns[nums.size() - 1] = true; // for the last entry
        bool ans;
        for(int i = nums.size() - 2; i >= 0; i--){
            // if the jump size is greater than the last index of nums
            // jump is possible
            if(i + nums[i] >= nums.size() - 1){
                idxAns[i] = true;
                continue;
            }
            // otherwise ans is a combination of all entries in idxAns 
            // within range of this nums[idx]
            ans = false;
            for(int j = i + 1; j <= i + nums[i]; j++){
                if(j >= nums.size()){
                    break;
                }else{
                    ans = ans || idxAns[j];
                }
                // if true is found, no need to check further
                if(ans){
                    break;
                }
            }
            // set the answer
            idxAns[i] = ans;
        }
        return idxAns[0];
    }
};

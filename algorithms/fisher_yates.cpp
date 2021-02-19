/*
Given an integer array nums, design an algorithm to randomly shuffle the array.

Implement the Solution class:

    Solution(int[] nums) Initializes the object with the integer array nums.
    int[] reset() Resets the array to its original configuration and returns it.
    int[] shuffle() Returns a random shuffling of the array.

 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

Constraints:

    1 <= nums.length <= 200
    -106 <= nums[i] <= 106
    All the elements of nums are unique.
    At most 5 * 104 calls will be made to reset and shuffle.
*/

class Solution {
public:
    vector<int> original, for_permutation;
    Solution(vector<int>& nums) {
        original = nums;
        for_permutation = original;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        fisher_yates(for_permutation);
        return for_permutation;
    }

    void fisher_yates(vector<int>& nums){
        // generate a random shuffle
        for(int i = 0; i < nums.size(); i++){
            // iterate over the array
            // generate a random number between the current index and the end
            int idx = i + rand()%(nums.size() - i);
            // swap the elements
            int temp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = temp;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
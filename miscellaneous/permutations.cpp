/*
https://leetcode.com/problems/permutations/
problem 46
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0){
            vector<int> temp;
            ans.push_back(temp);
            return ans;
        }
        if(nums.size() == 1){
            vector<int> temp;
            temp.push_back(nums[0]);
            ans.push_back(temp);
            return ans;
        }
        for(int i = 0; i < nums.size(); i++){
            // put the ith element in the first position, and call
            // permute on an array of the remaining elements
            vector<int> nums_1_less;
            for(int j = 0; j < nums.size(); j++){
                if(i != j){
                    nums_1_less.push_back(nums[j]);
                }
            }
            vector<vector<int>> permutations_1_less = permute(nums_1_less);
            for(int j= 0; j < permutations_1_less.size(); j++){
                vector<int> temp;
                temp.push_back(nums[i]);
                for(int k = 0; k < permutations_1_less[j].size(); k++){
                    temp.push_back(permutations_1_less[j][k]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

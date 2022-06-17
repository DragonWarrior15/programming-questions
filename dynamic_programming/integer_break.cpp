// https://leetcode.com/problems/integer-break/
/*
Given a positive integer n, break it into the sum of at least 
two positive integers and maximize the product of those integers. 
Return the maximum product you can get.

Example 1:
Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

Note: You may assume that n is not less than 2 and not larger than 58.
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> ans(n+1, 0);
        ans[1] = 1;
        ans[2] = 1;
        for(int i=3; i<=n; i++){
            for(int j=1; j<i; j++){
                // the maximum can be either j * (the max breakup of i-j) or j*(i-j)
                // because in the second case, we do no break up i-j, the first case
                // only considers the maxima from breaking up i-j
                ans[i] = max(max(ans[i], j * ans[i-j]), j * (i-j));
            }
            // cout << i << " " << ans[i] << endl;
        }
        return ans[n];
    }
};

// https://leetcode.com/problems/longest-palindromic-subsequence/
/*
Given a string s, find the longest palindromic subsequence's length
in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:
"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:
"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb". 
*/

/*
the solution uses a combination of recursion and memoization
the function calculating the legngth of longest palindromic substring
between indices sidx and eidx (inclusinve) is lps.. if dp[sidx][eidx] > 0
(note minimum palindromic substring is a single character and hence of length 1)
we return the already calculated value, otherwise the function recurses and
the value is stored in the matrix
the logic for calculating lps is straightforward
if len(substring) = 1, return 1 as that is the min length of palindrome
if len(substring) = 2, return 2 if both chars are same otherwise 
return 1 (the previous case)
otherwise, 
if string[sidx] == string[eidx] then we can add these two chars
into the palindrome and calculate lps in (sidx+1, eidx-1)
else, we consider two cases, either exclude the last character from palindrome
or exclude the first character from palindrome and calculate lps
ie, return max(lps(sidx, eidx-1), lps(sidx+1, eidx))
note that we do not consider the case of excluding both the chars from 
palindrome because this case is already a part of both of the above two cases
that were used in the max clause and this happens because of the way we
have defined our recursion (sidx+1, eidx-1 is a subset of sidx, eidx-1)
*/

class Solution {
public:
    vector<vector<int>>dp;
    string s;
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        for(int i=0; i<n; i++){
            dp.push_back(vector<int>(n, 0));
            dp[i][i] = 1;
        }
        s = s1;
        return max(1, lps(0, n-1));
    }

    int lps(int sidx, int eidx){
        if(sidx > eidx){
            return 0;
        }else if(sidx == eidx){
            // length 1 substring
            return dp[sidx][eidx];
        }else if(sidx + 1 == eidx){
            // length 2 substring
            if(dp[sidx][eidx] == 0){
                if(s[sidx] == s[eidx]){
                    dp[sidx][eidx] = 2;
                }else{
                    dp[sidx][eidx] = 1;
                }
            }
            return dp[sidx][eidx];
        }else{
            if(dp[sidx][eidx] == 0){
                if(s[sidx] == s[eidx]){
                    dp[sidx][eidx] = 2 + lps(sidx+1, eidx-1);
                }else{
                        int ans = 0;
                        ans = max(ans, lps(sidx, eidx-1));
                        ans = max(ans, lps(sidx+1, eidx));
                        // ans = max(ans, lps(sidx+1, eidx-1));
                        dp[sidx][eidx] = ans;
                }
            }
            return dp[sidx][eidx];
        }
        return 1;
    }
};

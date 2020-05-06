// https://leetcode.com/problems/longest-common-subsequence/
/*
Given two strings text1 and text2, return the length of their 
longest common subsequence. A subsequence of a string is a new 
string generated from the original string with some 
characters(can be none) deleted without changing the relative 
order of the remaining characters. (eg, "ace" is a subsequence 
of "abcde" while "aec" is not). A common subsequence of two strings 
is a subsequence that is common to both strings.
If there is no common subsequence, return 0.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:
    1 <= text1.length <= 1000
    1 <= text2.length <= 1000
    The input strings consist of lowercase English characters only.
*/

/*
consider the problem of lcs for aab and azb
since we want the longest substring, we start from the back
as this way we can greedily characters
compare the last two characters.. they are same and must be included
in the lcs, hence our answer becomes 1 + lcs(aa, az)
we compare the last characters again, but this time they are different
now we need to look at two smaller problems, comparing when a is removed
from the 1st string and comparing when we remove z from second string
(this is done because since they are not same, only one of them at the
most can be a part of the lcs)
hence the answer now is 1 + max(lcs(aa, a), lcs(a, az))
we recurse until one of them becomes empty at which point the lcs is 0 and
this is the trivial case for the problem

the logic of comparing the last character also stems from the fact that if
we know the lcs for text1 and text2, adding the same character in the end
will cause the lcs to increase by 1; on the other hand, if the added character
is different, say c1 and c2, then the lcs is simply the max of the lcs for
(text1c1, text2) and (text1, text2c2).. we can compare them separately because
comparing with both the characters attached is same as removing one of them
at a time since only one can be included in the lcs at most.. this breaking down
into smaller subsets allows for the problem to be reduced in size and easily
solvable iteratively/recursively.. the idea is to reduce the problem each time

to actually solve the problem, we look at the string forwards
so in essence, we will be solving all comparisons between different
length combinations of the two strings
we prepare the lcs array with 1st row and column as zero since they
correspond to the empty string cases in the recursion
now index i,j of the lcs array is simply lcs(text1[:i-1], text2[:j-1])
and we solve it using similar logic, if last characters, ie text1[i-1] and
text2[j-1] are same, simply return 1 + lcs(i-1, j-1) which is nothing but
1 + lcs(text1[:i-2], text2[j-2]); otherwise, we get the max from two subproblems
which is max(lcs(i-1,j), lcs(i,j-1)) which is nothing but the 
max(lcs(text1[:i-2], text2[:j-1]), lcs(text1[:i-1], text2[:j-2])) and all
of these subproblems we have already solved for
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size(), idx1, idx2;
        vector<vector<int>> lcs(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++){
            lcs[i][0] = 0;
        }
        for(int j=0; j<n; j++){
            lcs[0][j] = 0;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                // -1 adjustment since lcs array has first row and column
                // corresponding to the empty string
                if(text1[i-1] == text2[j-1]){
                    // this character must be included
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }else{
                    // consider the two subproblems, only removing the last
                    // character from text1 and only removing last from text2
                    // because at the most only one of them will be considered
                    // in the final sequence
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        // the answer is considering the complete string, the last index
        return lcs[m][n];
    }
};
// https://leetcode.com/problems/domino-and-tromino-tiling/
/*
We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape.
These shapes may be rotated.
XX  <- domino
XX  <- "L" tromino
X
Given N, how many ways are there to tile a 2 x N board? 
Return your answer modulo 10^9 + 7.

(In a tiling, every square must be covered by a tile. Two tilings are different 
if and only if there are two 4-directionally adjacent cells on the board such 
that exactly one of the tilings has both squares occupied by a tile.)

Example:
Input: 3
Output: 5
Explanation: 
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY

Note:
    N  will be in range [1, 1000].
*/

/*
the arrangement can end in the following patterns
XX or,
X
X or,
XYY
XXY or,
XXY
XYY

but for N above 4, some special patterns emerge
XYYZ XYYAAZ
XXZZ XXBBZZ and so on for occupying even number of spaces
and their corresponding mirror along horizontal axis

XYYZZ XYYBBCCE
XXAAZ XXAADDEE and so on for occupying odd number of spaces
and their corresponding mirrof along horizontal axis
*/

class Solution {
public:
    int numTilings(int N) {
        if(N == 0){
            return 0;
        }
        vector<int> ans(N+1, 0); int constant = 1000000007, i, j;
        ans[0] = 1;
        if(N >= 1){
            ans[1] = 1;
        }
        if(N >= 2){
            ans[2] = 2;    
        }
        if(N >= 3){
            ans[3] = 5;
        }
        for(i=4; i<=N; i++){
            ans[i] = (ans[i-1] + ans[i-2])%constant;
            // special shapes occur from 3 onwards
            for(j=3; j<=i; j++){
                ans[i] += (2*ans[i-j])%constant;
                ans[i] = ans[i]%constant;
            }
        }
        return ans[N];
    }
};

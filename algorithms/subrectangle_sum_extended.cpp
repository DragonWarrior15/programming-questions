// https://leetcode.com/problems/matrix-block-sum/
/*
Given a m * n matrix mat and an integer K, return a matrix 
answer where each answer[i][j] is the sum of all elements 
mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, 
and (r, c) is a valid position in the matrix. 

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]] 

Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n, K <= 100
    1 <= mat[i][j] <= 100

*/

/*
The logic is similar to subrectangle sum but slightly tweaked
consider the sample case of
1 2 3
4 5 6
7 8 9

we prepare a matrix whose i,j th entry stores the sum of the
subrectangle between 0,0 and i,j inclusive, but we also pad it on
left and top with zeros
0 0  0  0
0 1  3  6
0 5  12 21
0 12 27 45

the extra layer of zeros allows us to account for the region of the 
subrectangle falling outside the actual rectangle.
for instance, consider we want the value of answer[0][1] the required rectangle
will be
[-1][0]  [-1][2]
[1][0]   [1][2]
now we restrict this rectangle to be within the bounds of the cumul rectangle
i.e., rows between [0,m] and columns between [0,n]
[0][0] [0][2]
[1][0] [1][2]
the required sum is then cumul[1][2] - cumul[1][0] - cumu[0][2] + cumul[0][0]
since the first row and columns are zero, they will not affect the sum and this way
we have also included the first row and column of the original matrix into the sum value
*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n=mat[0].size(), i, j;
        // create a matrix that has the cumulative sum for all rows
        // <= i and all columns <= j
        vector<vector<int>> cumul(m+1, vector<int>(n+1, 0));
        for(j=0; j<n; j++){
            cumul[0][j] = 0;
        }
        for(i=0; i<m; i++){
            cumul[i][0] = 0;
        }
        for(i=1; i<=m; i++){
            for(j=1; j<=n; j++){
                cumul[i][j] = cumul[i][j-1] + cumul[i-1][j] - cumul[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        // now calculate the answer matrix as desired
        vector<vector<int>> answer(m, vector<int>(n, 0));
        int del_count = 0;
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                answer[i][j] = cumul[min(i+1+K, m)][min(j+1+K, n)] - cumul[min(i+1+K, m)][max(j-K, 0)] - cumul[max(i-K, 0)][min(j+1+K, n)] + cumul[max(i-K, 0)][max(j-K, 0)];
                // continue;
            }
        }
        return answer;
    }
};
/*
https://leetcode.com/problems/set-matrix-zeroes/
Given an m x n matrix. If an element is 0, set its entire row 
and column to 0. Do it in-place.

Follow up:
    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -2^31 <= matrix[i][j] <= 2^31 - 1
*/

/*
to solve the problem in place, we need an additional storage to store which
rows or columns must be filled with zeros. a simple idea will be to have an int
such that the bit corresposing to the row with a 0 is set to 1.
given the problem constraint, the total rows can be 200 and maximum size of
an int is only 64.
to solve the problem, we create an array of 8 elements, each a 32 bit int
thus, across the entire array, we can store the set bits for the 200 rows
we determine the index of the element for the array using modulo and quotient
operators as described below
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // encode information about which row and column to convert to 0
        // by setting the bit at the corresponding index as 1
        vector<int> rows (8, 0), cols (8, 0);
        int i, j;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    // dont do addition since same row can have multiple zeros
                    // index of array depends on how many rows are there, and
                    // what multiple of 32 we are looking at
                    // since each int in the array will be 32 bit, we use
                    // modulo operator to bring the shift to < 32 and shift
                    // operation is possible
                    rows[i/32] |= 1<<(i%32);
                    cols[j/32] |= 1<<(j%32);
                }
            }
        }
        // debug
        // cout << rows << " " << cols << endl;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if((rows[i/32] & 1<<(i%32)) || (cols[j/32] & 1<<(j%32))){
                    matrix[i][j] = 0;
                }
            }
        }
   }
};
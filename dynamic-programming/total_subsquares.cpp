// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
/*
Given a m * n matrix of ones and zeros, return how many square 
submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // initialize a 2d vector with 0s
        vector<vector<int>> square_count(m, vector<int>(n, 0));
        int total_squares = 0;
        
        // use a dp to solve, at index i,j we store the maximum size
        // of a square ending at that index
        for(int i=0; i < m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    square_count[i][j] = 0;
                }else{
                    if(i*j == 0){
                        // first cell or first row or first column
                        // only possible square is the cell itself
                        square_count[i][j] = 1;
                        total_squares += 1;
                    }else{
                        // take the minimum from all three directions
                        // and add 1 to that.. if all three directions are
                        // 1, only then is it possible to expand the square
                        square_count[i][j] = min(square_count[i-1][j-1], min(square_count[i-1][j], square_count[i][j-1])) + 1;
                        total_squares += square_count[i][j];
                    }
                }
            }
        }
        return total_squares;
    }
};
// https://leetcode.com/problems/arithmetic-slices/
/*
A sequence of number is called arithmetic if it consists of at 
least three elements and if the difference between any two 
consecutive elements is the same.
For example, these are arithmetic sequence:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.
1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. 
A slice of that array is any pair of integers (P, Q) such 
that 0 <= P < Q < N.
A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. 
In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the 
array A.
Example:
A = [1, 2, 3, 4]
return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and 
[1, 2, 3, 4] itself.
*/

/*
the logic is simply to avoid repeated calculations. suppose we are at an
index i such that a[i], a[i+1], a[i+2] are arithmetic, then we create a pointer
j=i+3 and we keep increasing it till a[j]-a[j-1] = a[i+1]-a[i] which is the
common difference of an arithmetic progression (ap). then all the numbers with
indices k, i<=k<j are in the ap. let the count of numbers be k, then the total
number of possible ap's is (n-3+1) + (n-4+1) + .. + (n-n+1) which is nothing but
number of length 3 ap's + length 4 ap's + .. + length n ap's. and this sum is
in a convenient form as ((n-2)*(n-1))/2
now we can simply skip all the numbers till j since the next possible new
ap will start from j-1 (j-2, j-1 and j are not in ap, but j-1, j can be in a new
ap and hence important to consider this). now we reset i to j-1 and redo the
whole process. this way we can find the sequences in a single pass through array.
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i=0, ans=0, d, j, n = A.size();
        if(n < 3){
            return 0;
        }
        while(i <= n-3){
            // check if i, i+1 and i+2 are arithmetic
            if(A[i+2] + A[i] == 2*A[i+1]){
                // in arithmetic progression
                d = A[i+1] - A[i];
                j = i+3;
                while(j < n){
                    // check if j and j-1 have the same difference
                    if(A[j] - A[j-1] == d){
                        // continue checking
                        j++;
                    }else{
                        // found the end point of this sequence run
                        break;
                    }
                }
                // calculate the total sequences
                ans += ((j-i - 2)*(j-i - 1))/2;
                // change i
                i = j-1;
            }else{
                // increase i by 1 as current i+1 and i+2 can form a different sequence;
                i++;
            }
        }
        
        return ans;
    }
};

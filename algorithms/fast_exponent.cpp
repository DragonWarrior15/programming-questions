/*
mplement pow(x, n), which calculates x raised to the power n (i.e. x^n).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Constraints:
    -100.0 < x < 100.0
    -2^31 <= n <= 2^31-1
    -10^4 <= x^n <= 10^4
*/

/*
use long long judiciously based on the problem constraints
we will use fast exponentiation here, the core idea is to reduce the
number of operations as much as possible, by breaking the exponent as a sum of
powers of 2, and only computing doubling of base multiple times

for instance, 3^10 can be rewritten as 3^(8 + 2) where 8 and 2 are powers of 2

we take a step back and first compute the following array
3^1, 3^2, 3^4, 3^8, stop filling this array when the next power > original exponent
the above array is updated by appending the square of the last element

to get the correct powers to pick from this array for calculating the 
final answer, we refer to the binary representation of the exponent.
*/

class Solution {
public:
    double myPow(double x, int n) {
        // base case
        if(x == 1 || exponent == 0){return 1.0;}
        // make the power positive
        long long exponent = n;
        bool reciprocal = false;
        if(exponent < 0){
            reciprocal = true;
            exponent *= -1;
        }
        std::vector<double> intermediate_ans;
        // store the intermediate answers in an array
        // insert the base case of first power
        intermediate_ans.push_back(x); long long power = 1; int idx = 0;
        while(true){
            intermediate_ans.push_back(intermediate_ans[idx] * intermediate_ans[idx]);
            idx++; power *= 2;
            // break condition
            if(power > exponent){
                break;
            }
        }
        // for debug
        // for(int i = 0; i < intermediate_ans.size(); i++){
            // cout << intermediate_ans[i] << " ";
        // }cout << endl;
        // generate the answer using set bits of n
        double ans = 1;
        idx = 0;
        while(exponent){
            // pick only the set bits to get corresponding index from array
            if(exponent & 1){
                // cout << exponent << " ";
                ans *= intermediate_ans[idx];
                // cout << ans << endl;
            }
            idx++; exponent >>= 1;
        }
        // get reciprocal if needed
        if(reciprocal){
            ans = 1/ans;
        }
        return ans;
    }
};

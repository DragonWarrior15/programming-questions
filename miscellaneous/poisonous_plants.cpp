/*
There are a number of plants in a garden. Each of these plants has been 
treated with some amount of pesticide. After each day, if any plant has more 
pesticide than the plant on its left, it dies.
You are given the initial values of the pesticide in each of the plants. 
Print the number of days after which no plant dies, i.e. the time after 
which there are no plants with more pesticide content than the plant to their left.

For example, pesticide levels p = [3, 6, 2, 7, 5]. Using a 1-indexed array, 
day 1 plants 2 and 4 die leaving p = [1, 3, 5]. On day 2, plant 3 of the current array 
dies leaving p = [1, 2]. As there is no plant with a higher concentration of pesticide 
than the one to its left, plants stop dying after day.

Input Format
The first line contains an integer N, the size of the array.
The next line contains N space-separated integers p[i].

Constraints
1 <= N <= 10**5
1 <= p[i] <= 10**9

Output Format
Output an integer equal to the number of days after which no plants die.

Sample Input
7
6 5 8 4 7 10 9

Sample Output
2

Explanation
Initially all plants are alive.
Plants = {(6,1), (5,2), (8,3), (4,4), (7,5), (10,6), (9,7)}
Plants[k] = (i,j) => jth plant has pesticide amount = i.
After the 1st day, 4 plants remain as plants 3, 5, and 6 die.
Plants = {(6,1), (5,2), (4,4), (9,7)}
After the 2nd day, 3 plants survive as plant 7 dies.
Plants = {(6,1), (5,2), (4,4)}
After the 2nd day the plants stop dying.
*/

/*
the idea is to use stacks to achieve and O(n) solution
suppose we add pesticide value and the life of plant as a pair to stack
when stack is empty, just add p[i], 0 (note that 1st plant of array never dies)
now, if the next element in array is larger than top of stack, it will die
on day 1.. hence add p[i], 1 to the stack
in the other case, when p[i] <= top of stack, we need to find the correct time
of death for this plant.. hence we pop off elements of stack while this inequality
holds (since all these plants present in the stack must first die to allow this p[i]
to die) we maintain a span = max(span, second element of the stack).. the life of p[i]
is simply span + 1 and we add p[i], span + 1.. but if the stack got emptied, 
it is not possible for this plant to die.. and we add p[i], 0 to the stack
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // read data
    int N; cin >> N;
    int p[N], i = N, days = 0, span; stack<int> pesticide, life;
    for(i = 0; i < N; i++){
        cin >> p[i];
    }
    i = 0;
    while(i < N){
        if(pesticide.empty()){
            pesticide.push(p[i]); life.push(0);
        }else{
            // compare the pesticide contents
            if(pesticide.top() < p[i]){
                // current plant will die on day 1
                pesticide.push(p[i]); life.push(1);
                days = max(days, 1);
            }else{
                // we need to find the day on which this plant dies
                // keep popping off elements, keeping track of max life
                span = 0;
                while(!pesticide.empty() and pesticide.top() >= p[i]){
                    span = max(span, life.top());
                    pesticide.pop(); life.pop();
                }
                if(pesticide.empty()){
                    // push 0 life as this plant cannot die
                    pesticide.push(p[i]); life.push(0);
                }else{
                    // push the span (essentially days count)
                    pesticide.push(p[i]); life.push(span + 1);
                    days = max(days, span + 1);
                }
            }
        }
        i++;
    }
    cout << days << endl;
    return 0;
}
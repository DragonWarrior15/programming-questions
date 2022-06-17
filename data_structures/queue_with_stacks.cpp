/*
A queue is an abstract data type that maintains the order in which 
elements were added to it, allowing the oldest elements to be removed 
from the front and new elements to be added to the rear. This is called 
a First-In-First-Out (FIFO) data structure because the first element 
added to the queue (i.e., the one that has been waiting the longest) 
is always the first one to be removed.

A basic queue has the following operations:
    Enqueue: add a new element to the end of the queue.
    Dequeue: remove the element from the front of the queue and return it.

In this challenge, you must first implement a queue using two stacks. Then process
queries, where each query is one of the following

types:
    1 x: Enqueue element x into the end of the queue.
    2: Dequeue the element at the front of the queue.
    3: Print the element at the front of the queue.

Function Description
Complete the put, pop, and peek methods in the editor below. 
They must perform the actions as described above.

Input Format
The first line contains a single integer q, the number of queries.
Each of the next q lines contains a single query in the form described 
in the problem statement above. All queries start with an integer denoting 
the query number, but only query 1 is followed by an additional space-separated 
value x, denoting the value to be enqueued.

Constraints
1 <= q <= 10**5
1 <= type <= 3
1 <= |x| <= 10**9

It is guaranteed that a valid answer always exists for each query of 
types 2 and 3.

Output Format
For each query of type 2, return the value of the element at the front of the 
fifo queue on a new line.

Sample Input
10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2

Sample Output
14
14
*/

/*
keep filling the first stack till elements are entered
once a pop/front operation is called, empty this stack into
the second stack and perform the requisite operation, no need to
fill back the first stack as any future pop/front operation
can be fulfilled using the second stack till it is not empty
this way one O(n) operation is saved everytime
when second stack is having some elements, simply fill the first
stack on a push operation
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            // simply put the element into the first stack
            stack_newest_on_top.push(x);
        }

        void pop() {
            // check if an element is already present in the stack oldest
            // if yes, pop from there, else transfer everything from first
            // pop from first stack into second stack
            if(!stack_oldest_on_top.empty()){
                stack_oldest_on_top.pop();
            }else{
                int temp;
                while(!stack_newest_on_top.empty()){
                    temp = stack_newest_on_top.top();
                    stack_newest_on_top.pop();
                    stack_oldest_on_top.push(temp);
                }
                stack_oldest_on_top.pop();
            }
        }

        int front() {
            // refer to the pop operaion for implementation logic
            int ans;
            if(!stack_oldest_on_top.empty()){
                ans = stack_oldest_on_top.top();
            }else{
                int temp;
                while(!stack_newest_on_top.empty()){
                    temp = stack_newest_on_top.top();
                    stack_newest_on_top.pop();
                    stack_oldest_on_top.push(temp);
                }
                ans = stack_oldest_on_top.top();
            }
            return ans;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

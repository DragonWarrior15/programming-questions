/*
There is a rectangular grid of gold mine. The grid has R rows and C columns.
So it has R*C cells in total. The rows are numbered from 1 to R and the columns 
are numbered from 1 to C. The top most row has number 1, the row next to it 
has number 2 and so on. Similarly, the left most column has number 1, the 
column next to it has number 2 and so on. Each cell in the grid has a unique 
coordinate which is (x, y) where x is the row number and y is the column number 
of that particular cell.
Each cell in the grid has certain amount of gold in it. Total gold in a 
sub rectangle of the grid is the sum of all units of gold contained in the cells 
that are inside the rectangle. Your task is to find the total gold in the given 
sub rectangle.
A sub rectangle of the grid is defined by four integers x1, y1, x2 and y2. 
A cell (x, y) belongs to the sub rectangle if and only if x1 <= x <= x2 
and y1 <= y <= y2.

Input
First line of the input contains two space separated integers, R and C. 
It is followed by R lines, each line has C space separated integers. Each 
integer denotes the units of gold present in that particular cell.
Next line has number Q, it is followed by Q queries each query in a single line. 
Each query is four space separated integers x1, y1, x2 and y2.

Output
For each query, you have to print a single number the total gold contained in 
that sub rectangle.

Constraints
1 <= R <= 1000
1 <= C <= 1000
1 <= x1 <= x2 <= R
1 <= y1 <= y2 <= C
Amount of gold in each cell is an integer from 0 to 10^6
SAMPLE INPUT
4 4
2 8 9 7
5 8 1 7
5 7 3 5
4 8 7 4
4
1 2 4 2
1 4 2 4
1 1 4 2
2 4 2 4

SAMPLE OUTPUT
31
14
47
7
*/

/*
The logic is borrowed from image processing where we calculate intensity of
pixels. First, we simply calculate a new rectangle such that the value equals
sum of all pixels in rectangle where x <= current row and y <= current col
This can be recursively and easily calculated (see preprocess logic below).
Next, we can answer the queries in O(1) time by using the following expression
ans = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1]
This can be read as series of set operations, first we take sum of all cells
in <= x2 and <= y2 range, then we subtract 2 smaller blocks, one horizontal
and one vertical. But in these 2 subtractions, we have subtracted the region
<= x1 and <= y1 twice. Hence we add it back once.
*/

#include <iostream>
using namespace std;

int main(){
    // read the data
    long long R, C; cin >> R >> C;
    long long G[R+1][C+1], S[R+1][C+1], i, j;
    for(i=0; i<C+1; i++){G[0][i] = 0;}
        for(i=0; i<R+1; i++){G[i][0] = 0;}
    for(i=1; i<R+1; i++){
        for(j=1; j<C+1; j++){
            cin >> G[i][j];
        }
    }
    // preprocess the rectangle
    for(i=0; i<R+1; i++){
        for(j=0; j<C+1; j++){
            if(i==0){
                // first row
                if(j==0){
                    // first cell
                    S[i][j] = G[i][j];
                }else{
                    S[i][j] = S[i][j-1] + G[i][j];
                }
            }else{
                if(j==0){
                    S[i][j] = S[i-1][j] + G[i][j];
                }else{
                    S[i][j] = S[i][j-1] + (S[i-1][j] - S[i-1][j-1]) + G[i][j];
                }
            }
        }
    }
    // debugging
    /*
    for(i=0; i<R+1; i++){
        for(j=0; j<C+1; j++){
            cout << G[i][j] << " ";
        }cout << endl;
    }
    for(i=0; i<R+1; i++){
        for(j=0; j<C+1; j++){
            cout << S[i][j] << " ";
        }cout << endl;
    }
    */
    // read the queries
    long long Q, x1, x2, y1, y2, ans;
    cin >> Q;
    for(i=0; i<Q; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        // answer in O(1) through logic
        cout << S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1] << endl;
    }
    return 0;
}
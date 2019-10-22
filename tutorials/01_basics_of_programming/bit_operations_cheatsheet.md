# Bitwise Operations Cheatsheet
## Check if number is power of 2
```cpp
bool isPowerOfTwo(int x){
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
}
```
## Count number of ones in binary representation
```cpp
int count_one (int n){
    while(n){
        n = n&(n-1);
       count++;
    }
    return count;
}
```
## Check if i<sup>th</sup> bit is set
```cpp
bool check (int N){
    return (N & (1 << i)) ? true | false
}
```

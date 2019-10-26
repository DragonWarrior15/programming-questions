/*
It's Lolympics 2016 right now, and we all know who's the best player there 
right now: Kalyani! Obviously, he has a huge female fan following and he has 
to make sure they are all happy and rooting for him to win the gold medals.
But with fan following comes arrogance and lack of time. Thus, he has 
sufficient time to interact with atmost T of his fans. Each fan is defined 
by two parameters : Name and Fan Quotient. The name defines the name of the 
fan, while the fan quotient is a measure of the fan's devotion towards Kalyani. 
Higher the fan quotient, greater is the devotion. Kalyani now wants to meet T 
of his fans. While selecting the fans he wants to meet, he wants to make sure 
that a fan with a higher fan quotient should be given a chance in favour of 
those with lesser fan quotient. In case of ties, he sorts their name 
lexicographically and chooses the lexicographically lesser named fan.

Given details of N fans, can you help out Kalyani by giving him a list of 
fans he would be interacting with?

Input Format :
The first line contains N and T, the number of fans and the maximum number 
of fans Kalyani can meet. Each of the next N lines contains a string and an 
integer separated by a space. The string denotes the name of the fan while 
the integer depicts the fan quotient.

Output Format :
Output T lines, each containing the name of the fans selected. Fans with 
higher fan quotient should be outputted first and in case of a tie, the 
lexicographically minimum name should come first.

Constraints :
1 <= T <= N <= 1000
1 <= length of name <= 20
1 <= fan quotient <= 10^9
Name would only consist of characters in set [a-z]. It is not guaranteed 
that the names are distinct.

SAMPLE INPUT
3 2
surbhi 3
surpanakha 3
shreya 5

SAMPLE OUTPUT
shreya
surbhi

Explanation
We can see that the ordering would be {"shreya", "surbhi", "surpanakha"}. 
Hence the best two are shreya and surbhi.
*/

#include <iostream>
using namespace std;

void swap(long long *arr, string *s, long long idx1, long long idx2);
int compare(long long *arr, string *s, long long idx1, long long idx2);
void quicksort(long long *arr, string *s, long long start, long long end, long long size);

int main(){
    // read the data
    long long T, N, i; cin >> N >> T;
    long long Q[N]; string s[N];
    for(i=0; i<N; i++){cin >> s[i] >>  Q[i];}
    // sort the data using quick sort
    quicksort(Q, s, 0, N, N);
    // output the result
    i=N-1;
    while(i>=N-T){
        cout << s[i] << endl; i--;
    }
    return 0;
}

void swap(long long *arr, string *s, long long idx1, long long idx2){
    long long tmp = arr[idx1]; arr[idx1] = arr[idx2]; arr[idx2] = tmp;
    string tmp1 = s[idx1]; s[idx1] = s[idx2]; s[idx2] = tmp1;
}

int compare(long long *arr, string *s, long long idx1, long long idx2){
    if(arr[idx1] > arr[idx2]){
        return 1;
    }else if(arr[idx1] < arr[idx2]){
        return 2;
    }else{
        if(s[idx1] > s[idx2]){
            return 2;
        }else if(s[idx1] < s[idx2]){
            return 1;
        }else{
            return 0;
        }
    }
}

void quicksort(long long *arr, string *s, long long start, long long end, long long size){
    // perform quicksort on a given array
    // check the base case of length 1 or 2
    if(end - start == 1 | end == start){
        ;
    }else if(end - start == 2){
        if(compare(arr, s, start, end-1) == 1){
            swap(arr, s, start, end-1);
        }
    }else{
        // select a random pivot element first
        long long pivot = start + rand()%(end-start); long long i, j;
        // put the pivot at the start of array
        swap(arr, s, start, pivot);
        // sort the array such that smaller elements are on left
        // side and vice versa
        j = start+1;
        for(i=start+1; i<end; i++){
            if(compare(arr, s, i, start) == 2){
                swap(arr, s, i, j);
                j++;
            }
        }
        // new pivot is at j-1
        swap(arr, s, start, j-1);
        // perform quicksort on either side
        quicksort(arr, s, start, j-1, size);
        quicksort(arr, s, j, end, size);
    }
}
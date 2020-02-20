#include <iostream>
#include <cstdlib> // for rand()
using namespace std;

int digit_count(long long N);
void quicksort(int *arr, int start, int end, int size);

int main(){
    // read the data
    long long T; cin >> T;
    long long N, i;
    int digits;
    while(T--){
        // read the number
        cin >> N; digits = digit_count(N);
        int D[digits];
        i = 0;
        while(N > 0){
            D[i] = N%10; N/=10; i++;
        }
        quicksort(D, 0, digits, digits);
        int j=0;
        while(N < 2){

            N++;
        }


    }
    return 0;
}

int digit_count(long long N){
    int dc = 0;
    while(N > 0){
        N/= 10; dc++;
    }
    return dc;
}

void quicksort(int *arr, int start, int end, int size){
    // perform quicksort on a given array
    // check the base case of length 1 or 2
    if(end - start == 1 | end == start){
        ;
    }else if(end - start == 2){
        if(arr[start] > arr[end-1]){
            int tmp = arr[start]; arr[start] = arr[end-1]; arr[end-1] = tmp;
        }
    }else{
        // select a random pivot element first
        int pivot = start + rand()%(end-start); int tmp, i, j;
        // put the pivot at the start of array
        tmp = arr[start]; arr[start] = arr[pivot]; arr[pivot] = tmp;
        // sort the array such that smaller elements are on left
        // side and vice versa
        j = start+1;
        for(i=start+1; i<end; i++){
            if(arr[i] < arr[start]){
                tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
                j++;
            }
        }
        // new pivot is at j-1
        tmp = arr[start]; arr[start] = arr[j-1]; arr[j-1] = tmp;
        // perform quicksort on either side
        quicksort(arr, start, j-1, size);
        quicksort(arr, j, end, size);
    }
}

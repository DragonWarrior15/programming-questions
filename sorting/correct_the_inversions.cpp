/*
In an array arr the elements at indices i and j (where i<j) form an 
inversion if arr[i] > arr[j]. In other words, inverted elements arr[i] and
arr[j] are considered to be "out of order". To correct an inversion, 
we can swap adjacent elements.

For example, consider the dataset [2, 4, 1]. It has two inversions: (2, 1) and
(4, 1). To sort the array, we must perform two swaps to correct the inversions.

Given d datasets, print the number of inversions that must be swapped 
to sort each dataset on a new line.

Input Format
The first line contains an integer d the number of datasets.
Each of the next d pairs of lines is as follows:
    The first line contains an integer n the number of elements
    The second line contains n space-separated integers arr[i]

Constraints
1 <= d <= 15
1 <= n <= 10**5
1 <= arr[i] <= 10**7

Output Format
For each of the d datasets, return the number of inversions that must be 
swapped to sort the dataset.

Sample Input
2  
5  
1 1 1 2 2  
5  
2 1 3 1 2

Sample Output
0  
4   

*/

/*
correct the inversions => think in terms of sorting
best sorting algorithm we can use is merge sort or quick sort
using merge sort, simply record the number of elements swapped
in the merge steps
*/

#include <iostream>
using namespace std;

unsigned long g_swap_count;
void mergesort(unsigned int *arr, unsigned int start, 
               unsigned int end);

int main(){
    // read the data
    int d; unsigned int a[100000];
    unsigned int i, n;
    cin >> d;
    while(d--){
        cin >> n;
        for(i=0; i<n; i++){
            cin >> a[i];
        }
        g_swap_count = 0;
        mergesort(a, 0, n-1);
        cout << g_swap_count << endl;
    }
    return 0;
}

void mergesort(unsigned int *arr, unsigned int start, 
               unsigned int end){
    unsigned int temp, mid, i, j, k;
    // swaps done in a sorting algorithm are the number of inversions
    if(end - start == 0){
        // single element no need to sort
        ;
    }else if(end - start == 1){
        // two elements, sort here
        if(arr[start] > arr[end]){
            temp = arr[start]; arr[start] = arr[end]; arr[end] = temp;
            g_swap_count++;
        }
    }else{
        // recursively do the mergesort
        mid = (end + start)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        // merge the sorted lists
        unsigned int t[end - start + 1];
        k = 0;
        i = start; j = mid + 1;
        while(k < end - start + 1 && i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                t[k] = arr[i];
                i++;
            }else{
                t[k] = arr[j];
                j++;
                // since we are technically displacing mid - i + 1
                // elements of the left array by this operation
                g_swap_count += (mid - i + 1);
            }
            k++;
        }
        // at least one of i or j is exhausted, fill the remaining array
        if(i > mid){
            temp = j;
        }else{
            temp = i;
        }
        while(k < end - start + 1){
            t[k] = arr[temp];
            k++; temp++;
        }
        for(i=0; i<end-start+1; i++){
            arr[start + i] = t[i];
        }
    }
}

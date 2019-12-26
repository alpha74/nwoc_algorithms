// C++ implementation of Radix Sort 
// Sample input:
// [170, 45, 75, 90, 802, 24, 2, 66]
// Sample output:
// [2, 24, 45, 66, 75, 90, 170, 802]
#include<iostream> 
using namespace std; 
  
// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int num, int exp) 
{ 
    int output[num]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < num; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = num - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < num; i++) 
        arr[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixsort(int arr[], int num) 
{ 
    // Find the maximum number to know number of digits 
    int max = getMax(arr, num); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; max/exp > 0; exp *= 10) 
        countSort(arr, num, exp); 
} 
  
// A utility function to print an array 
void print(int arr[], int num) 
{ 
    for (int i = 0; i < num; i++) 
        cout << arr[i] << " "; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
    int num = sizeof(arr)/sizeof(arr[0]); 
    radixsort(arr, num); 
    print(arr, num); 
    return 0; 
} 
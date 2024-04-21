#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,3,-2,4,-5};
    int n = sizeof(arr) / sizeof(arr[0]);
   
    int maxEndingHere = INT_MIN;        // to store the sum of currSubArray ending at idx i
    int maxSoFar = INT_MIN;             // to store the maxSum out of all subarrays 

    for(int i=0; i<n; i++){
        maxEndingHere = max(maxEndingHere + arr[i], arr[i]);    // curSubArr me add karke acha result hai, ya yahan se nayi subarray shuru karke acha result hai
        maxSoFar = max(maxSoFar, maxEndingHere);    // is the curSubArr sum beating the maxSum out of all subarray sums
    }

    cout<<"Maximum Subarray Sum: "<<maxSoFar<<endl;

    return 0;
}



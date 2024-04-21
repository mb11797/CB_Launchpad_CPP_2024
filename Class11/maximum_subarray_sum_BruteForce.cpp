#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int maxSubarraySum = INT_MIN;
    int minSubarraySum = INT_MAX;
    for(int i=0; i<n; i++){
        // i -> to select starting of current window
        for(int j=i; j<n; j++){
            // j -> to selet ending of current window

            // Print current Window
            int curSubarraySum = 0;
            for(int k=i; k<=j; k++){
                curSubarraySum = curSubarraySum + arr[k];
            }

            if(curSubarraySum > maxSubarraySum){
                maxSubarraySum = curSubarraySum;
            }

            if(curSubarraySum < minSubarraySum){
                minSubarraySum = curSubarraySum;
            }

            cout<<"Sum of Subarray from "<<i<<" -> "<<j<<" = "<<curSubarraySum<<endl;
        }
        cout<<endl;
    }

    cout<<"Maximum Subarray Sum: "<<maxSubarraySum<<endl;
    cout<<"Minimum Subarray Sum: "<<minSubarraySum<<endl;

    return 0;
}


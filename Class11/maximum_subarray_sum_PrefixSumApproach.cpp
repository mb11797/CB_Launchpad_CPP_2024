#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,3,-2,4,-5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int prefixSum[n];

    // memset() -> Prepopulate any array with some initial value
    memset(prefixSum,0, sizeof prefixSum);

    for(int i=0; i<n; i++){
        prefixSum[i] = (i > 0 ? prefixSum[i-1] : 0) + arr[i];
    }

    cout<<"arr[] =>       ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"   ";
    cout<<endl;

    cout<<"prefixSum[] => ";
    for(int i=0; i<n; i++)
        cout<<prefixSum[i]<<"   ";
    cout<<endl;


    int maxSubarraySum = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            // i -> j => subarray is isolated
            int curSubarraySum_i_to_j = prefixSum[j] - (i > 0 ? prefixSum[i-1] : 0);
            if(curSubarraySum_i_to_j > maxSubarraySum){
                maxSubarraySum = curSubarraySum_i_to_j;
            }
        }
    }


    cout<<"Maximum Subarray Sum: "<<maxSubarraySum<<endl;

    return 0;
}



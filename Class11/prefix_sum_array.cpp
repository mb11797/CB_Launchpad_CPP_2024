#include<iostream>
using namespace std;

int main(){
    int arr[] = {2,3,6,1,9,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int prefixSum[n];

    // memset() -> Prepopulate any array with some initial value
    memset(prefixSum,0, sizeof prefixSum);

    /*
    // M-1
    for(int i=0; i<n; i++){
        if(i == 0)
            prefixSum[i] = arr[i];
        else
            prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    */

    /*
    // M-2
    prefixSum[0] = arr[0];
    for(int i=1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    */

    // M-3
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


    return 0;
}



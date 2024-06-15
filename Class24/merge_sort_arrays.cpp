#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;

    int i = s;
    int j = mid+1;
    int k = s;

    int temp[100];

    while(i<=mid && j<=e){
        if(arr[i]<arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=mid)
        temp[k++] = arr[i++];

    while(j<=e)
        temp[k++] = arr[j++];

    //Now we need to copy all elements from temp array to original array
    for(int i=s; i<=e; i++)
        arr[i] = temp[i];

}


void merge_sort(int arr[], int s, int e){
    if(s>=e)
        return;

    //follow 3 steps:
    //1st: Divide
    int mid = (s+e)/2;

    //2nd: Recursively sort the arrays - s->mid and mid+1->e
    merge_sort(arr, s, mid);
    merge_sort(arr, mid+1, e);

    //3rd: Merge the two parts
    merge(arr, s, e);

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    merge_sort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<", ";

    return 0;
}

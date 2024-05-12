#include<iostream>
using namespace std;

int counSetBits(int n){
    int count = 0;
    while(n > 0){
        n = n & (n-1);
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;

    cout<<counSetBits(n)<<endl;

    return 0;
}
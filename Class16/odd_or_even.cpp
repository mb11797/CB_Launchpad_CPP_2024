#include<iostream>
using namespace std;

int checkOdd(int n){
    return n & 1;
}

int main(){
    int n;
    cin>>n;

    cout<<checkOdd(n)<<endl;

    return 0;
}
#include<iostream>
using namespace std;

int findSum(int a, int b){
	int sum = a + b;
	return sum;
}

void printSum(int a, int b){
	int sum = a + b;
	cout<<"In printSum(), Sum of 4 and 89 = "<<sum<<endl;
}

int main(){

	int sum = findSum(4, 89);
	cout<<"In main(), Sum of 4 and 89 = "<<sum<<endl;
	cout<<"In main(), Half Sum of 4 and 89 = "<<sum / 2<<endl;


	printSum(4, 89);

	return 0;
}
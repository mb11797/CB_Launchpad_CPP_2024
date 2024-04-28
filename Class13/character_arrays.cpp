#include<iostream>
using namespace std;

int main(){
	// Incorrect
	char arr[5] = {'h', 'e', 'l', 'l', 'o'};
	cout<<arr<<endl;

	// Correct
	char arr1[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
	cout<<arr1<<endl;

	// Correct
	char arr2[] = "hello";
	cout<<arr2<<endl;

	/*
	// Wrong -> Error -> no place for \0
	char arr3[5] = "hello";
	cout<<arr3<<endl;
	*/

	// Correct -> Error Rectified -> created place for \0
	char arr4[6] = "hello";
	cout<<arr4<<endl;

	// char arr5[15];
	// cin>>arr5;
	// cout<<arr5<<endl;

	char arr6[25];
	cin.getline(arr6, 25, '\n');
	cout<<arr6<<endl;

	return 0;
}
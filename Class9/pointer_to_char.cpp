#include<iostream>
using namespace std;

int main(){
	char ch = 'A';

	cout<<ch<<endl;
	cout<< &ch <<endl;		// prints all the characters until a '\0' is not found
	cout<< (int *)(&ch) <<endl;		// we specifically mentioned the compiler that it is a pointer to ch
	cout<< (char)*((int *)(&ch)) <<endl;		// we specifically mentioned the compiler that it is a pointer to ch


	char arrOfChars[] = "Hello";
	cout<<arrOfChars<<endl;

	// int arrOfIntegers[] = {1,2,3,4,5};
	// cout<<arrOfIntegers<<endl;

	// int arrOfFloats[] = {1.1f,2.2f,3.3f,4.4f,5.5f};
	// cout<<arrOfFloats<<endl;

	cout<< &arrOfChars <<endl;
	cout<< (int *)&arrOfChars <<endl;
	cout<< (void *)&arrOfChars <<endl;


	return 0;
}
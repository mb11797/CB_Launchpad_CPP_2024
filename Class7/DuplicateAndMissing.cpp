#include<iostream>
using namespace std;

void findDuplicateAndMissingElements(int arr[], int n){
	for(int elmnt=1; elmnt<=5; elmnt++){
		int count = 0;
		for(int i=0; i<5; i++){
			if(elmnt == arr[i]){
				count++;
			}
		}

		if(count == 0){
			cout<<"Missing Element is: "<<elmnt<<"\n";
		}
		else if(count == 2){
			cout<<"Duplicate Element is: "<<elmnt<<"\n";
		}
	}
}


int main(){

	int arr[5] = {1,2,3,2,4};

	findDuplicateAndMissingElements(arr, 5);

	return 0;
}


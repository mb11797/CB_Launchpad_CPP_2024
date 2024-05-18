#include<iostream>
using namespace std;

int find_kth_bit(int n, int k){
	int mask = 1<<k;
	if((n & mask) > 0){
		return 1;
	}
	return 0;
	// Alternative Way -> 1 liner
	// return (n & (1<<k)) > 0;
}

int find_unique_no(int arr[], int n){

	int ans = 0;
	// string s = "";
	// string unique_no_binary = "";
	for(int k=0; k<32; k++){
		// k -> bitPos
		int count = 0;
		for(int i=0; i<n; i++){
			if(find_kth_bit(arr[i], k))
				count++;
		}

		// s = to_string(count) + " " + s;
		// unique_no_binary = to_string(count % 3) + " " + unique_no_binary;

		int kthBitInAns = count % 3;
		
		// ans = ans + kthBitInAns * pow(2, k);
		ans = ans + kthBitInAns * (1<<k);
	}
	// cout<<s<<endl;
	// cout<<unique_no_binary<<endl;
	return ans;
}


int main(){
	// all nos thrice except 1 unique no

	int n = 7;
	int arr[7] = {1,3,5,3,3,1,1};

	cout<<find_unique_no(arr, n)<<endl;


	return 0;
}




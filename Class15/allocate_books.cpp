#include<iostream>
#include<vector>
using namespace std;

bool kyaMidNoOfPagesKStudentsMeDivideHoPaaye(int books[], int n, int threshold, int nStudents){
	int student = 1;
	int curStudentPages = 0;
	for(int i=0; i<n; i++){
		if(curStudentPages + books[i] <= threshold){
			curStudentPages += books[i];
		}
		else{
			student++;
			curStudentPages = books[i];
			if(student > nStudents){
				return false;
			}
		}
	}

	return true;
}

int findMaxNoOfPages(int books[], int n, int k){
	int totalPages = 0;
	int minPages = 0;

	for(int i=0; i<n; i++){
		minPages = min(minPages, books[i]);
		totalPages += books[i];
	}

	// minPages -> minm no of pages that can be allocated to a student
	// totalPages -> maxm no of pages that can be allocated to a student

	int beg = minPages;
	int en = totalPages;

	int ans = 0;
	while(beg <= en){
		int mid = (beg + en) / 2;

		if(kyaMidNoOfPagesKStudentsMeDivideHoPaaye(books, n, mid, k)){
			ans = mid;
			en = mid-1;
		}
		else{
			beg = mid+1;
		}
	}
	return ans;
}

int main(){

	int books[4] = {12,34,67,90};
	int n = 4;
	int nStudents = 2;

	cout<<findMaxNoOfPages(books, n, nStudents)<<endl;

	return 0;
}
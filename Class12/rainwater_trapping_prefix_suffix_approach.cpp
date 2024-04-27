#include<iostream>
using namespace std;

int main(){
	int heights[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int n = 12;
	int lftMax[12];
	int rytMax[12];

	// Calc lftMax for every index
	lftMax[0] = heights[0];
	for(int i=1; i<n; i++)
		lftMax[i] = max(lftMax[i-1], heights[i]);

	rytMax[n-1] = heights[n-1];
	for(int i=n-2; i>=0; i--)
		rytMax[i] = max(rytMax[i+1], heights[i]);

	// Print heights
	for(int i=0; i<n; i++)
		cout<<heights[i]<<" ";
	cout<<endl;

	// Print lftMax
	for(int i=0; i<n; i++)
		cout<<lftMax[i]<<" ";
	cout<<endl;	

	// Print rytMax
	for(int i=0; i<n; i++)
		cout<<rytMax[i]<<" ";
	cout<<endl;	

	// Calculate total water
	int totalWaterAccumulated = 0;
	for(int i=0; i<n; i++){
		totalWaterAccumulated += min(lftMax[i], rytMax[i]) - heights[i];
	}

	cout<<"TotalWaterAccumulated = "<<totalWaterAccumulated<<endl;

	return 0;
}
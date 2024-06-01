#include<iostream>
#include<vector>
using namespace std;

int findWays(int nRows, int nCols, int row, int col){
	// cout<<row<<" "<<col<<" "<<nRows<<" "<<nCols<<endl;
	if(row == (nRows-1) and col == (nCols-1)){
		return 1;
	}

	if(row == nRows){
		return 0;
	}

	if(col == nCols){
		return 0;
	}

	int x = findWays(nRows, nCols, row, col+1);
	int y = findWays(nRows, nCols, row+1, col);

	return x + y;
}

int main(){

	int m, n;
	cin>>m>>n;

	int ans = findWays(m, n, 0, 0);
	cout<<ans<<endl;

	return 0;
}
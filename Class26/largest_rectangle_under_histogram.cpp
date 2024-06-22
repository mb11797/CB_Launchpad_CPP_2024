#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int calcLargestArea(vector<int> heights){
	int maxArea = 0;

	stack<int> stk;
	int n = heights.size();

	for(int i=0; i<=n; i++){
		while(!stk.empty() && (i == n || (heights[stk.top()] > heights[i]))){
			// stk.top() ki calculation aaj hogi
			int ht = heights[stk.top()];
			stk.pop();

			int width;
			if(!stk.empty()){
				width = i - stk.top() - 1;				
			}
			else{
				width = i;
			}

			maxArea = max(maxArea, ht*width);
		}
		stk.push(i);
	}
	return maxArea;
}
int main(){

	int n;
	cin>>n;
	vector<int> heights;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		heights.push_back(temp);
	}

	cout<<calcLargestArea(heights)<<endl;

	return 0;
}
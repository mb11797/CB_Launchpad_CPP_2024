#include<iostream>
using namespace std;

void subsequences(string s, int curIdx, string osf){
	if(curIdx == s.length()){
		cout<<osf<<endl;
		return;
	}

	subsequences(s, curIdx+1, osf);
	subsequences(s, curIdx+1, osf + s[curIdx]);
}

int main(){

	string s;
	cin>>s;

	string osf = "";	// output so far
	subsequences(s, 0, "");

	return 0;
}
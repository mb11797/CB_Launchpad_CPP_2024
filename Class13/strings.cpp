#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool MyComparator(string a, string b){
	return a.length() > b.length();
}

int main(){
	string s = "hello";
	cout<<s<<endl;

	string s1("world");
	cout<<s1<<endl;

	// string s2;
	// cin>>s2;
	// cout<<s2<<endl;

	string s3;
	getline(cin, s3);
	cout<<s3<<endl;


	string strArr[5] = {"ball", "elephant", "apple", "cat", "dog"};
	cout<<strArr<<endl;

	for(int i=0; i<5; i++)
		cout<<strArr[i]<<" ";
	cout<<endl;

	sort(strArr, strArr+5);

	for(int i=0; i<5; i++)
		cout<<strArr[i]<<" ";
	cout<<endl;


	// vector<string> strVec = {"ball", "elephant", "apple", "cat", "dog"};
	// std::vector<std::string> strVec{"apple", "banana", "orange", "grape"};
	vector<string> strVec(5, "apple");
	strVec[0] = "ball";
	strVec[1] = "alephant";
	strVec[2] = "apple";
	strVec[3] = "cat";
	strVec[4] = "dog";

	sort(strVec.begin(), strVec.end());
	for(int i=0; i<5; i++)
		cout<<strVec[i]<<" ";
	cout<<endl;

	// MyComparator -> comparator -> functor
	sort(strVec.begin(), strVec.end(), MyComparator);
	for(int i=0; i<5; i++)
		cout<<strVec[i]<<" ";
	cout<<endl;

	return 0;
}
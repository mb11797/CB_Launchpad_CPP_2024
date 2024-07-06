#include<iostream>
#include<map>
using namespace std;

int main(){

	string word = "codingblocks";

	map<char, int> freqMap;

	for(char ch: word){
		// M-1
		freqMap[ch]++;

		/*
		// M-2
		if(m.count(key) > 0){
			freqMap[key]++;
		}
		else{
			freqMap[key] = 1;
		}
		*/
	}

	for(pair<char, int> p: freqMap){
		cout<<p.first<<" -> "<<p.second<<endl;
	}
	cout<<endl;

	for(auto p: freqMap){
		cout<<p.first<<" -> "<<p.second<<endl;
	}
	cout<<endl;

	return 0;
}
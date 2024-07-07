#include<iostream>
#include "hashmap.h"
using namespace std;

int main(){
	Hashmap<int> h;

	h.insert("banana", 30);
	h.insert("apple", 50);
	h.insert("orange", 20);


	h.print();

	h.erase("banana");

	h.print();

	h.insert("waterMellon", 40);

	h.print();

	if(h.search("apple"))
		cout<<"h[apple]: "<<*h.search("apple")<<endl;
	else
		cout<<"Not Found"<<endl;

	h.erase("banana");

	h.print();

	return 0;
}
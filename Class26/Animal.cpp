#include<iostream>
using namespace std;

class Animal{
private:

protected:

public:
	int legs;
	int eyes;

	void see(){
		cout<<"Animal sees";
	}

	void eat(){
		cout<<"Animal eats";
	}

	void speak(){
		cout<<"Animal speaks";
	}


};

class Human : Animal{
private:

public:
	void eat(){
		cout<<"Animal eats using mouth with spoons";
	}


};

int main(){

	Human bhuvan = new Human();
	bhuvan.eat();		// O/p: Animal eats using mouth with spoons

	return 0;
}



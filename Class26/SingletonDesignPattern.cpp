#include<iostream>
using namespace std;

class Animal{
private:

	Animal animal = NULL;

	Animal(){

	}

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

	Animal getInstance(){
		if(animal == NULL){
			animal = new Animal();
			return animal;
		}
		return animal;
	}


};

int main(){

	Human bhuvan = new Human();
	bhuvan.eat();		// O/p: Animal eats using mouth with spoons

	return 0;
}



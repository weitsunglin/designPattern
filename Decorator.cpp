#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

//装饰器允許物件动态地添加新行为。
//物件和装饰器要遵循相同接口( Component， Decorator)
//由此产生的物件将获得所有装饰器的叠加行为。

class Component{
public:
	virtual void Operation() = 0;
};

class concreteComponent :public Component{
public:
	void Operation(){
		cout << "concreteComponent" << endl;
	}
};

class Decorator : public Component{
public:
	Decorator( Component *p ) : p_Component( p ) {}
	void Operation(){
		if ( p_Component != NULL ){
			p_Component->Operation();
		}
	}
private:
	Component *p_Component;
};

class DecoratorA : public Decorator {
public:
	DecoratorA( Component *p ) : Decorator( p ) {}
	void Operation(){
		add_status();
		Decorator::Operation();
	}
	void add_status(){
		cout << "DecoratorA " << endl;
	}
};

class DecoratorB :public Decorator{
public:
	DecoratorB(Component *p) : Decorator(p) {}
	void Operation(){
		add_bahavior();
		Decorator::Operation();
	}

	void add_bahavior(){
		cout << "DecoratorB " << endl;
	}
};

class DecoratorC :public Decorator{
public:
	DecoratorC(Component *p) : Decorator(p) {}
	void Operation(){
		add_bahavior();
		Decorator::Operation();
	}

	void add_bahavior(){
		cout << "DecoratorC " << endl;
	}
};

int main(){

	Component* object = new concreteComponent();

	Decorator *a = new DecoratorA( object );
	a->Operation();
	cout << "-----------------------------------------------------" << endl;

	Decorator *b = new DecoratorB( object );
	b->Operation();
	cout << "------------------------------------------------------" << endl;

	Decorator *ab = new DecoratorB( a );
	ab->Operation();

	cout << "-----------------------------------------------------" << endl;

	Decorator *c = new DecoratorC(object);
	c->Operation();

	cout << "-----------------------------------------------------" << endl;

	Decorator *ac = new DecoratorC( a );
	ac->Operation();

	cout << "-----------------------------------------------------" << endl;

	Decorator *bc = new DecoratorC( b );
	bc->Operation();

	string mystr; //用來避免函數被RETURN出去，用cin卡住
	getline( cin, mystr );
	return 0;
}
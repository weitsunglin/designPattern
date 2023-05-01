#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

// 簡單工廠

// 特點: 工廠封裝創建具體產品的物件函數
// 缺點: 擴展性麻煩，當新增產品時，需要去修改工廠類

// ShoesFactory：負責創建產品實例
// Shoes：產品父類
// NewBalance：具體產品類

enum TYPE{
	NB //值從0開始
};

class Shoes{
public:
	virtual ~Shoes() {}
	virtual void Show() = 0; //純虛函數
};

class NewBalance : public Shoes{
public:
	void Show(){
		cout << "ShowNewBalance" << endl;
	}
};

class ShoesFactory{
public:
	Shoes *CreateShoes( TYPE type ){
		switch ( type ){
		case NB:
			return new NewBalance();
			break;
		default:
			cout << "ShowdefaultShoes" << endl;
			return NULL;
			break;
		}
	}
};

int main(){
	ShoesFactory shoesFactory;
	Shoes *NBShoes = shoesFactory.CreateShoes( NB );
	//delete指针，只是回收该指针指向的堆空间，指针值不變
	//也就是说，delete並不將指针删除，同时指针仍然指向原来的那個地址，需手動将其赋值為NULL
	if ( NBShoes != NULL ){
		NBShoes->Show();
		delete NBShoes;
		NBShoes = NULL; 
	}
	cout << "NBShoes Adrress" << NBShoes << endl; //00000000 >> 空值地址，因為它被釋放掉了
	string mystr; //用來避免函數被RETURN出去，用cin卡住
	getline(cin, mystr);
	return 0;
}
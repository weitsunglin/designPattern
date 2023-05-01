#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

// 工廠模式

// 缺點:
// 相較於簡單工廠，擴充產品，會新增更多類別( 工廠 及 產品 )
// 每個工廠只能生產一個產品

// Shoes：產品父類
// NiKeShoes：具體產品類
// ShoesFactory：工廠父類
// NiKeProducer: 負責創建產品實例

class Shoes{
public:
	virtual ~Shoes() {}
	virtual void Show() = 0;
};

class NiKeShoes : public Shoes{
public:
	void Show(){
		cout << "NiKeShoes" << endl;
	}
};

class ShoesFactory{
public:
	virtual Shoes *CreateShoes() = 0;
	virtual ~ShoesFactory() {}
};

class NiKeProducer : public ShoesFactory{
public:
	Shoes *CreateShoes(){
		return new NiKeShoes();
	}
};

int main(){
	ShoesFactory *niKeProducer = new NiKeProducer();
	Shoes *nikeShoes = niKeProducer->CreateShoes();
	nikeShoes->Show();

	delete nikeShoes;
	delete niKeProducer;
	nikeShoes = NULL;
	niKeProducer = NULL;

	string mystr; //用來避免函數被RETURN出去，用cin卡住
	getline(cin, mystr);
	return 0;
}
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//不同的行為，完成相同目的

class Strategy{
public:
	virtual ~Strategy(){}
	virtual void exec() = 0;
};

class StrategyA :public Strategy{
public:
	void exec(){ cout << "StrategyA::exec()" << endl; }
};

class StrategyB :public Strategy{
public:
	void exec(){ cout << "StrategyB::exec()" << endl; }
};

class Client{
public:
	//建構子前面加上 explicit 只能用顯性轉換
	explicit Client( Strategy* strategy ) : _strategy( strategy ) {}
	void set_strategy( Strategy* strategy ){ _strategy = strategy; }
	void exec(){ _strategy->exec(); }
private:
	Strategy* _strategy;
};

int main(){

	StrategyA sa;
	StrategyB sb;

	// 基於策略建構客戶端
	Client ca( &sa );
	Client cb( &sb );
	ca.exec();
	cb.exec();

	cout << "=========================" << endl;

	// 客户端設置策略( StrategyA,  StrategyB )
	ca.set_strategy( &sb );
	cb.set_strategy( &sa );
	ca.exec();
	cb.exec();

	string mystr; //用來避免函數被RETURN出去，用cin卡住
	getline( cin, mystr );

	return 0;
}
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

//有些物件只需要一個實例，例如伺服器程式中通常會把設定檔資訊讀入到一個單例物件
//之後使用單例 getInstance 然後就可以在任何地方(其他類別)獲得這些設定資訊

class Setting {
public:
	static Setting& getInstance() {
		static Setting instance;
		return instance;
	}


	// copy constructor ( 控制預設函式 )
	Setting( Setting const& ) = delete;

	// assignment operator
	void operator = ( Setting const& ) = delete;

private:
	Setting() {}
};

int main() {
	Setting &s = Setting::getInstance();
	Setting &s2 = Setting::getInstance();
	cout << "setting addr: " << &s << endl;
	cout << "setting2 addr: " << &s2 << endl;
	string mystr; //用來避免函數被RETURN出去，用cin卡住
	getline(cin, mystr);
	return 0;
}


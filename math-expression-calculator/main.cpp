#include "calculator.h"
#include <iostream>
using namespace std;
int main(){
	string input;
	cout << "Enter expression(without spaces)" << endl;
	cin >> input;
	expression a(input);
	cout << a.evaluate() << endl;
	system("pause");
	return 0;
}
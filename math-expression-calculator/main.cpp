#include "calculator.h"
#include <iostream>
using namespace std;
int main(){
	string input;
	cout << "Enter expression(without spaces)" << endl;
	cin >> input;
	expression a(input);
	cout << a.get_str_expression() << endl;
	for (int i = 0; i < a.get_expression().size(); i++) cout << a.get_expression()[i] << " ";
	cout << endl;
	cout << a.evaluate() << endl;
	system("pause");
	return 0;
}
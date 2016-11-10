#include "calculator.h"
#include <iostream>
using namespace std;
int main(){
	string input;
	cout << "Enter expression(without spaces)" << endl;
	cin >> input;
	expression a(input);
	for (int i = 0; i < a.get_expression().size(); i++) cout << a.get_expression()[i] << " ";
	cout << endl;
	for (int i = 0; i < a.get_element_type().size(); i++) cout << i << ":" << a.get_element_type()[i] << endl;
	cout << a.evaluate() << endl;
	cout << endl;
	system("pause");
	return 0;
}
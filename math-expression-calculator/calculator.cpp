#include "calculator.h"
float string_to_float(std::string str){
	float result;
	std::istringstream(str) >> result;
	return result;
}
std::string expression::get_str_expression(){
	return str_expression;
}
std::vector<std::string> expression::get_expression(){
	return vect_expression;
}
std::vector<std::string> expression::get_element_type(){
	return element_type;
}
int expression::get_operator_priority(std::string _operator){
	for (int i = 0; i < OPERATIONS; i++){
		if (_operator == operation[i].str) return operation[i].priority;
	}
}
std::string expression::get_neutral_element(std::string _operator){
	for (int i = 1; i < OPERATIONS; i++){
		if (_operator == operation[i].str) return operation[i].neutral_element;
	}
}
void expression::unary_to_binary(){
/*
* This function converts unary + or - to binary by adding neutral element before operator.
* Supported expressions: 
*-a + b = 0 - a + b
* a+(-b) = a + (0 - b)
* a+(-b + c) = a + (0 - b + c)
* Not supported: a - - b, a - - - b, etc.
*/
	for (int i = 0; i < vect_expression.size(); i++){
		if (i > 0){
			if (element_type[i] == "operator" && vect_expression[i - 1] == "("){
				element_type.insert(element_type.begin() + i, "operand");
				vect_expression.insert(vect_expression.begin() + i, get_neutral_element(vect_expression[i]));
			}
		}
		else{
			if (element_type[i] == "operator"){
				vect_expression.insert(vect_expression.begin() + i, get_neutral_element(vect_expression[i]));
				element_type.insert(element_type.begin() + i, "operand");
			}
		}
	}
}
void expression::fill_expr_vect(std::string expr){
	std::string current_operand;
	std::string current_operator;
	std::string current_long_operator;
	for (int i = 0; i < expr.size(); i++){
		if (isdigit(expr[i]) || expr[i] == '.'){
			while ((isdigit(expr[i]) || expr[i] == '.') && i < expr.size()){
				current_operand.push_back(expr[i]);
				i++;
			}
			vect_expression.push_back(current_operand);
			element_type.push_back("operand");
			current_operand.clear();
		}else{
			while (!isdigit(expr[i]) && i < expr.size()){
				if (expr[i] != '(' || expr[i] != ')'){
					if (isalpha(expr[i])){
						current_long_operator.push_back(expr[i]);
					}else{
						if (current_long_operator.size() != 0){
							vect_expression.push_back(current_long_operator);
							element_type.push_back("operator");
							current_long_operator.clear();
						}
						current_operator.clear();
						current_operator.push_back(expr[i]);
						vect_expression.push_back(current_operator);
						element_type.push_back("operator");
					}
				}else{
					if (current_long_operator.size() != 0){
						vect_expression.push_back(current_long_operator);
						element_type.push_back("operator");
						current_long_operator.clear();
					}
					current_operator.clear();
					current_operator.push_back(expr[i]);
					vect_expression.push_back(current_operator);
					element_type.push_back("operator");
				}
				i++;
			}
			current_operator.clear();
			current_long_operator.clear();
		}
		i--;
	}
}
void expression::set_operations(){
	operation[1].priority = -1;
	operation[1].str = "(";
	operation[2].priority = 2;
	operation[2].str = "+";
	operation[2].neutral_element = "0";
	operation[3].priority = 2;
	operation[3].str = "-";
	operation[3].neutral_element = "0";
	operation[4].priority = 1;
	operation[4].str = "*";
	operation[5].priority = 1;
	operation[5].str = "/";
	operation[6].priority = 0;
	operation[6].str = "^";
	operation[7].priority = 1;
	operation[7].str = "sin";
	operation[7].neutral_element = "1";
	operation[8].priority = 1;
	operation[8].str = "cos";
	operation[8].neutral_element = "1";
	operation[9].priority = 1;
	operation[9].str = "ln";
	operation[9].neutral_element = "1";
	operation[10].priority = 1;
	operation[10].str = "exp";
	operation[10].neutral_element = "1";

}
float expression::eval(std::string _operator, float a, float b){
	if (_operator == operation[2].str) return a + b;
	if (_operator == operation[3].str) return a - b;
	if (_operator == operation[4].str) return a * b;
	if (_operator == operation[5].str) return a / b;
	if (_operator == operation[6].str) return pow(a,b);
	if (_operator == operation[7].str) return sin(b);
	if (_operator == operation[8].str) return cos(b);
	if (_operator == operation[9].str) return log(b);
	if (_operator == operation[10].str) return pow(M_E, b);
}
expression::expression(std::string expr){
	set_operations();
	str_expression = expr;
/**********************************************************************
* If expression starts with "(", it will be converted to 1*expression
* Do not remove this block!
* ...really, don't do that
**********************************************************************/
	if (expr[0] == '('){
		expr.insert(expr.begin(), '*');
		expr.insert(expr.begin(), '1');
	}
	expr.push_back(';');
	fill_expr_vect(expr);
	for (int i = 0; i < vect_expression.size(); i++){
		if (vect_expression[i] == "e" || vect_expression[i] == "pi"){
			if (vect_expression[i] == "e") vect_expression[i] = "2.71828182845904523536";
			if (vect_expression[i] == "pi") vect_expression[i] = "3.14159265358979323846";
			element_type[i] = "operand";
		}
	}
	unary_to_binary();
}
bool expression::can_pop(std::string operator_1, std::string operator_2){
	if (operators_stack.size() == 0) return false;
	if (operands_stack.size() < 2) return false;
	return 
		(get_operator_priority(operator_1) >= get_operator_priority(operator_2))
		&& get_operator_priority(operator_1) >= 0
		&& get_operator_priority(operator_2) >= 0;
}
void expression::pop(){
	float b = operands_stack.back();
	operands_stack.pop_back();
	float a = operands_stack.back();
	operands_stack.pop_back();
	operands_stack.push_back(eval(operators_stack.back(), a, b));
	float val = operands_stack.back();
	std::string oper = operators_stack.back();
	operators_stack.pop_back();
}
float expression::evaluate(){
	for (int i = 0; i < vect_expression.size(); i++){
		if (element_type[i] == "operand"){
			operands_stack.push_back(string_to_float(vect_expression[i]));
		}
		if (element_type[i] == "operator"){
			if (vect_expression[i] == ")"){
				while (operators_stack.size() > 0 && operators_stack.back() != "("){
					pop();
				}
				operators_stack.pop_back();
			}
			else{
				if (operators_stack.size() > 0 && can_pop(vect_expression[i], operators_stack.back())){
					while (operators_stack.size() > 0 && can_pop(vect_expression[i], operators_stack.back())){
						pop();
					}
					operators_stack.push_back(vect_expression[i]);
				}else{
					operators_stack.push_back(vect_expression[i]);
				}
	
			}
		}
	}
	return operands_stack[0];
}
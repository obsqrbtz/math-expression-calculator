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
	for (int i = 0; i < 6; i++){
		if (_operator == operation[i].str) return operation[i].priority;
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
		}
		else{
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
expression::expression(std::string expr){
	str_expression = expr;
	expr.push_back(';');
	fill_expr_vect(expr);

	operation[0].priority = -1;
	operation[0].str = "(";

	operation[2].priority = 2;
	operation[2].str = "+";

	operation[3].priority = 2;
	operation[3].str = "-";

	operation[4].priority = 1;
	operation[4].str = "*";

	operation[5].priority = 1;
	operation[5].str = "/";

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
	if (operators_stack.back() == operation[2].str) operands_stack.push_back(a + b);
	if (operators_stack.back() == operation[3].str) operands_stack.push_back(a - b);
	if (operators_stack.back() == operation[4].str) operands_stack.push_back(a * b);
	if (operators_stack.back() == operation[5].str) operands_stack.push_back(a / b);
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
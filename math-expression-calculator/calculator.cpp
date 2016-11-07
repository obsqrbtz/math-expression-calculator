#include "calculator.h"
float string_to_float(std::string str){
	float result;
	std::istringstream(str) >> result;
	return result;
}
int expression::get_operator_priority(std::string _operator){
	if (_operator == operation[0].str) return operation[0].priority;
	if (_operator == operation[1].str) return operation[1].priority;
	if (_operator == operation[2].str) return operation[2].priority;
	if (_operator == operation[3].str) return operation[3].priority;
	if (_operator == operation[4].str) return operation[4].priority;
	if (_operator == operation[5].str) return operation[5].priority;
}
void expression::fill_stacks(std::string expr){
	std::string current_operand;
	std::string current_operator;
	std::string current_long_operator;
	for (int i = 0; i < expr.size(); i++){
		if (isdigit(expr[i]) || expr[i] == '.'){
			while ((isdigit(expr[i]) || expr[i] == '.') && i < expr.size()){
				current_operand.push_back(expr[i]);
				i++;
			}
			ar_expression.push_back(current_operand);
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
							ar_expression.push_back(current_long_operator);
							element_type.push_back("operator");
							current_long_operator.clear();
						}
						current_operator.clear();
						current_operator.push_back(expr[i]);
						ar_expression.push_back(current_operator);
						element_type.push_back("operator");
					}
				}else{
					if (current_long_operator.size() != 0){
						ar_expression.push_back(current_long_operator);
						element_type.push_back("operator");
						current_long_operator.clear();
					}
					current_operator.clear();
					current_operator.push_back(expr[i]);
					ar_expression.push_back(current_operator);
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
	fill_stacks(expr);
// Define operations and priorities
	operation[0].priority = -1;
	operation[0].str = "(";

	operation[1].priority = 0;
	operation[1].str = ")";

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
	if (get_operator_priority(operator_1) > get_operator_priority(operator_2)){
		return false;
	}else{
		return true;
	}
}
void expression::pop(std::string _operator){
	float a = operands_stack[operands_stack.size() - 1];
	float b = operands_stack[operands_stack.size() - 2];
}
std::string expression::get_str_expression(){
	return str_expression;
}
std::vector<std::string> expression::get_operators_stack(){
	return operators_stack;
}
std::vector<float> expression::get_operands_stack(){
	return operands_stack;
}
std::vector<std::string> expression::get_expression(){
	return ar_expression;
}
std::vector<std::string> expression::get_element_type(){
	return element_type;
}
/*float expression::evaluate(){
	float result = 0;
	for (int i = 0; i < ar_expression.size(); i++){
		if (element_type[i] == "operand"){
			operands_stack.push_back(string_to_float(ar_expression[i]));
		}
		if (element_type[i] == "operator"){
			
		}
	}
	return result;
}
*/
#pragma once
#include <string>
#include <vector>
#include <sstream>
struct operations{
	public:
		std::string str;
		int priority;
};
class expression{
	private:
		std::string str_expression;
		std::vector<std::string> vect_expression;
		std::vector<std::string> element_type;
		operations operation[10];
		std::vector<float> operands_stack;
		std::vector<std::string> operators_stack;
		bool can_pop(std::string, std::string);
		void pop();
		void fill_expr_vect(std::string);
		void set_priorities();
		float eval(std::string, float, float);
	public:
		expression(std::string);
		std::string get_str_expression();
		std::vector<std::string> get_element_type();
		std::vector<std::string> get_expression();
		int get_operator_priority(std::string);
		float evaluate();
};
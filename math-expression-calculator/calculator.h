#pragma once
#define _USE_MATH_DEFINES
#define OPERATIONS 11
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
struct operations{
	public:
		std::string str;
		std::string neutral_element;
		int priority;
};
class expression{
	private:
		std::string str_expression;
		std::vector<std::string> vect_expression;
		std::vector<std::string> element_type;
		operations operation[OPERATIONS];
		std::vector<float> operands_stack;
		std::vector<std::string> operators_stack;
		int get_operator_priority(std::string);
		std::string get_neutral_element(std::string);
		bool can_pop(std::string, std::string);
		void pop();
		void fill_expr_vect(std::string);
		void unary_to_binary();
		void set_operations();
		float eval(std::string, float, float);
	public:
		expression(std::string);
		std::string get_str_expression();
		std::vector<std::string> get_element_type();
		std::vector<std::string> get_expression();
		float evaluate();
};
# Math expression calculator
## Supported operations
	- +, -
	- *, /
	- ^ - exponentiation
	- sin(), cos()
	- exp(x) = e^x
	- ln()
## Constants
	-pi
	-e
## Usage
**Add to project**:  
Just add `calculator.cpp` and `calculator.h` to project and include `calculator.h`
```c++
	#include "calculator.h"
```
**Constructor:**
```c++
	expression name(string expression);
```
**Calculate expression:**
```c++
	name.evaluate();
```
**Get source string:**
```c++
	name.get_str_expression();
```
**Get internal representation of expression(vector):**
```c++
	name.get_expression();
```
**Get types of expression elements(operand/operator), based on internal representation(vector):**
```c++
	name.get_element_type();
```
## Example
```c++
	expression expr("ln(e)");
	float x = expr.evaluate();
```
## Notes
Expressions should be passed to constructor without spaces.  
Expressions like a--b, a+-b, ---b are invalid

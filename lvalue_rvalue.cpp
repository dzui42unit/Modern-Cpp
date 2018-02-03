#include <iostream>

// lvalue - an object that occupies some identifiable location in memory
// rvalue - any object that is not a lvalue

class 	Test
{
public:
	Test(void)
	{

	}
	~Test()
	{

	}

	void	modify(void)
	{

	}
};

int 	sum(int x, int y)
{
	return (x + y);
}

// adding a const int &val will give an opportunity to pass here an rvalue

int 	sqr(const int &val)
{
	return (val * val);
}

// most of the varibles in a C++ are lvalue

// misconception 1: function or operator always yield rvalue
// misconception 2: lvalue are modifiable; (constants are not modifiable)
// misconception 3: rvalues are not modifiable

int 	myglb;

int 	&foo(void)
{
	// function returns lvalue

	return (myglb);
}

int 	main(void)
{
	// lvalue example

	int 	i;			// i is a lvalue
	int 	*ptr_i;
	Test 	obj;		// lvalue of user defined type (class)

	ptr_i = &i;			// i's address is identifiable
	i = 5;				// a memory content is modified

	// rvalue example

	int x;

	x = 2;				// 2 is an rvalue
	x = i + 2;			// (i + 2) is also a rvalue

	// i + 2 = 4;		Error code
	// 2 = i;			Error code

	Test	t;
	int 	res;

	t = Test(); 		// Test() is rvalue of the user defined type (class)
	res = sum(3,4);		// sum(3,4) is rvalue

	// reference can be assigned only with a lvalue

	int &ref1 = res;		// Ok. No errors
	// int &ref2 = 5;			// Error code

	// only a const reference can be assigned with the rvalue

	const int &cref = 10;	// Ok. No errors

	// examples

	sqr(res); 		// Ok. No errors
	sqr(5);			// Error, 5 is rvalue

	// rvalue can be used to create an lvalue

	int v[3];

	*(v + 2) = 4;

	// misconception 1: function or operator always yield rvalue
	// function returns an lvalue and can be assigned

	foo() = 50;

	// operator[] almost always generats lvalue

	int arr[3] = { 1, 2, 3 };

	arr[2] = 50;

	// misconception 2: lvalue are modifiable; (constants are not modifiable)
	
	const int cval = 15;

	// misconception 3: rvalues are not modifiable
	// it is true for built in types
	// and not true for user defined types

	obj.modify();	// modify() can change the state of the object

	return (0);
}
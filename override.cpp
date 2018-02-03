#include <iostream>
#include <string>

class 	BaseClass
{
public:
	virtual void	func_a(void)
	{
		std::cout << "Base func_a()" << std::endl;
	}
	virtual void	func_b(void) const
	{
		std::cout << "Base func_b()" << std::endl;
	}
	virtual void	func_c(int c = 0)
	{
		std::cout << "Base func_c()" << std::endl;
	}
	void			func_d(void)
	{
		std::cout << "Base func_d()" << std::endl;
	}
};

/*
	This part of code demonstrates the problem that 
	will not be detected by a compiler.
	With the help of keyword override we will not get an undefined behavior during the inheritance.
*/

class 	DerivedClassProblematic
{
public:

	// Everything is OK. No errors, signature in the derived class is the same as in the base

	virtual void 	func_a(void)
	{
		std::cout << "DerivedProblematic func_a()" << std::endl;
	}

	// In the BaseClass func_b(void) is a const member function
	// that is why in the derived class it will be a new member function
	// and func_b(void) const will no be overriden in a derived class

	virtual void	func_b(void)
	{
		std::cout << "DerivedProblematic func_b()" << std::endl;
	}

	// BaseClass::func_c(int val) has another type of parameter
	// so it means that this code cerates a new member func_c(double val) in DerivedClass
	// and does not override the function of a base class

	virtual void	func_c(double val = 0.0)
	{
		std::cout << "DerivedProblematic func_c()" << std::endl;
	}
};

// keyword override will explicitly tell the compiler that 
// this member function should be override
// if something wrong with the signatures of the fumctions
// it will cause a compilation error instead of creating new member functions

class 	DerivedClass
{
public:

	// Everything is OK. No errors, signature in the derived class is the same as in the base

	virtual void 	func_a(void) override
	{
		std::cout << "DerivedProblematic func_a()" << std::endl;
	}

	// In the BaseClass func_b(void) is a const member function
	// that is why in the derived class it will be a new member function
	// and func_b(void) const will no be overriden in a derived class
	// compilation error

	virtual void	func_b(void) override
	{
		std::cout << "DerivedProblematic func_b()" << std::endl;
	}

	// BaseClass::func_c(int val) has another type of parameter
	// so it means that this code cerates a new member func_c(double val) in DerivedClass
	// and does not override the function of a base class
	// compilation error

	virtual void	func_c(double val = 0.0) override
	{
		std::cout << "DerivedProblematic func_c()" << std::endl;
	}
};

int		main(void)
{
	return (0);
}
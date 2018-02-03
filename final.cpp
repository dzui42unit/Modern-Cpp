#include <iostream>
#include <string>

// keyword final is used to prevent an ability to override a member-function

class BaseA
{
public:
	virtual	void	func(void) final
	{

	}
};

// this code will cause a compilation error
// it is forbiden to override a function specified as final

class DerivedA : public BaseA
{
public:
	virtual void	func(void)
	{

	}
};

// keyword final tells that it is forbiden to inherit from this class

class BaseB final
{
public:
	void	func(void)
	{

	}
};

// it will cause a compilation error
// because it is not allowed to inherit from a BaseB class, it is specified with final keyword

class DerivedB : public BaseB
{
public:
	void	func(void)
	{

	}
}

int		main(void)
{
	return (0);
}
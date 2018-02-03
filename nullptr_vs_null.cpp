#include <iostream>

void	foo(int var)
{
	std::cout << "foo(int var) called" << std::endl;
}

void	foo(void *var_ptr)
{
	std::cout << "foo(void *var_ptr)" << std::endl;
}

int		main(void)
{
	std::cout << "foo() -> passed NULL as an argument: ";
	foo(NULL);
	std::cout << "foo() -> passed nullptr as an argument: ";
	foo(nullptr);
	return (0);
}
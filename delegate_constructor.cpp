#include <iostream>
#include <string>

// example of usage of the delegate constructor C++11

class 	Test
{
private:
	int			val;
	std::string	str;
public:
		Test()
		{
			std::cout << "Test() called" << std::endl;
			val = 0;
			str = "no data";
		}
		Test(int v) : Test()
		{
			val = v;
			std::cout << "Test(int) called" << std::endl;
		}
		Test(std::string s) : Test()
		{
			str = s;
			std::cout << "Test(std::string) called" << std::endl;
		}
	void	print_info(void)
	{
		std::cout << "val: " << val << std::endl;
		std::cout << "str: " << str << std::endl;
	}
	~Test()
	{
		std::cout << "~Test() called" << std::endl;
	}
};

int		main(void)
{
	Test	a;
	a.print_info();
	std::cout << std::endl;
	Test	b(12);
	b.print_info();
	std::cout << std::endl;
	Test	c("String");
	c.print_info();
	std::cout << std::endl;
	return (0);
}
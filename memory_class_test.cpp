#include "memory_class.hpp"
#include <vector>

void	print_vector(std::vector<int>	&vec)
{
	std::cout << "standart vector: ";
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

class 	kek
{
public:
	kek()
	{

	}
	~kek()
	{
		std::cout << "kek destructed " << std::endl;
	}
	kek 	&operator=(const kek &)
	{
		return (*this);
	}
};

int		main(void)
{
	MemoryClass<int> 	cont(2);
	MemoryClass<int>	cnt;
	std::vector<int>	vec(10);
	MemoryClass<kek>	kek_c;

	/*
		push_back test for the container with reserved elements for 2 elements
	*/

	cont.push_back(12);
	cont.print_data();
	cont.push_back(43);
	cont.print_data();
	cont.push_back(42);
	cont.print_data();

	std::cout << std::endl;
	kek_c.push_back(kek());
	kek_c.push_back(kek());
	kek_c.pop();
	std::cout << std::endl;


	/*
		test of pop()
	*/

	cont.pop();
	cont.print_data();
	cont.pop();
	cont.print_data();
	cont.pop();
	cont.print_data();
	
	/*
		push_back test for the container constructed with the default constructor
	*/

	cnt.push_back(1);
	cnt.push_back(2);
	cnt.push_back(3);
	cnt.push_back(4);
	cnt.push_back(5);
	cnt.push_back(6);
	cnt.push_back(7);
	cnt.push_back(8);
	cnt.push_back(9);
	cnt.push_back(10);
	cnt.push_back(11);

	/*
		pop_back test
	*/

	while (cnt.size() > 0)
	{
		std::cout << "size of container: " << cnt.size() << std::endl;
		std::cout << "its content ";
		cnt.print_data();
		std::cout << std::endl;
		cnt.pop();
	}
	std::cout << "size = " << cnt.size() << std::endl;
	try
	{
		cnt.pop();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		cnt.back();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/*
		pop() and push_back() test
	*/

	std::cout << "size of container: " << cont.size() << std::endl;
	std::cout << "its content: ";
	cont.print_data();
	cont.pop();
	std::cout << "size of container: " << cont.size() << std::endl;
	std::cout << "its content with reserved: ";
	cont.print_data_res();
	cont.push_back(66);
	cont.push_back(77);
	cont.push_back(88);
	std::cout << "size of container: " << cont.size() << std::endl;
	std::cout << "its content: ";
	cont.print_data();
	cont.pop();
	int test = cont.back();
	test = 12;
	cont.print_data();
	try
	{
		cont.assert(77);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
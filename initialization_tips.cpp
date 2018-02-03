#include <iostream>
#include <string>
#include <initializer_list>
#include <vector>

// initializer_list<T> obejct can be uses for using it for creating an object
// that can be created by means of it

class 	MyVector
{
private:
	std::vector<int>	vec;
public:
	MyVector(const std::initializer_list<int> &init_list)
	{
		for (std::initializer_list<int>::iterator itr = init_list.begin(); itr != init_list.end(); itr++)
		{
			vec.push_back(*itr);
		}
	}
	void	print_vector(void)
	{
		for (const auto &e : vec)
		{
			std::cout << e << std::endl;
		}
	}
};

// Unifrom initialization search order
// 1. initializer list constructor
// 2. constructor that takes the list of parameters
// 3. aggregate initializer

class 	Human
{
private:
	std::string	name;
	int 		age;
public:
	Human(std::string nm, int a) : name(nm), age(a) {}
	void	print_human(void)
	{
		std::cout << "Human name: " << name << std::endl;
		std::cout << "Human age: " << age << std::endl;
	}
};

int 	main(void)
{
	MyVector	vec1{ 1, 2, 3, 4, 5 };		// initializer_list constructor
	MyVector 	vec2 = { 6, 7, 8, 9, 10 }; 	// aggreate initializer

	std::cout << "MyVector	vec1{ 1, 2, 3, 4, 5 }; elements:" << std::endl;
	vec1.print_vector();
	std::cout << std::endl;
	std::cout << "MyVector 	vec2 = { 6, 7, 8, 9, 10 }; elements:" << std::endl;
	vec2.print_vector();
	std::cout << std::endl;

	Human human1 = { "Dima", 19 };			// aggreate initializer
	Human human2{ "Christy", 22 }; 			// initializer_list constructor

	std::cout << "Human human1 = { \"Dima\", 19 }: " << std::endl;
	human1.print_human();
	std::cout << std::endl;
	std::cout << "Human human2 = { \"Christy\", 22 }: " << std::endl;
	human2.print_human();

	return (0);
}
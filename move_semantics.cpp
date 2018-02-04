#include <iostream>

class 	Array
{
private:
	int		*arr;
	int		size;
public:

		// default constructor that allocates a memory for 128 integers

		Array() : size(128), arr(new int[size])
		{
			std::cout << "Array - default constructor" << std::endl;
		}

		// constructor that takes as a parameter number of elements in array

		Array(int nb) : size(nb), arr(new int[size])
		{
			std::cout << "Array - constructor" << std::endl;
		}

		// copy constructor, that takes lvalue

		Array(const Array &ar) : size(ar.size), arr(new int[size])
		{
			std::cout << "Array - copy constructor" << std::endl;
		}

		// move constructor, that takes an rvalue

		Array(Array &&ar) : size(ar.size), arr(ar.arr)
		{
			std::cout << "Array - move constructor" << std::endl;
			ar.arr = nullptr;
		}

		// destructor

		~Array()
		{
			std::cout << "Destructor" << std::endl;
			delete []arr;
		}
};


// function that produces an object by value

Array 	create_array(int nb)
{
	Array obj(nb);
	return (obj);
}

int		main(void)
{
	Array 	ar1(12);				// constructor 
	Array 	ar2(ar1);				// copy constructor
	Array 	ar3(create_array(3));	// move constructor
	return (0);
}
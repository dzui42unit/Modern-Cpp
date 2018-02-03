#include <iostream>

/*
	1. the most useful place for rvalue reference is overloading
	copy constructor and copy assignment operator to achieve move semantics

	2. move semantics is implemented for all STL containers
*/

void	print_nb(int &i)
{
	std::cout << "lvalue reference: " << i << std::endl;
}

void	print_nb(int &&i)
{
	std::cout << "rvalue referene: " << i << std::endl;
}

/*

this function will cause a problem
a problam with the choice of which one function to choose

void	print_nb(int i)
{
	std::cout << "pass by value: " << i << std::endl;
}

*/

// a class that represents a vector of double values

class 	Vector
{
private:
	double	*arr;
	int		size;
public:
	Vector() = delete;

	// constructor that takes an int value and allocates the array

	Vector(int nb)							
	{
		size = nb;
		arr = new double[nb];
		for (int i = 0; i < size; i++)
			arr[i] = 0.0;
	}
	~Vector()
	{
		delete arr;
	}

	// copy constructor, that makes a deep copy of the array
	// takes as a parameter an lvalue
	
	Vector(const Vector &v)					
	{										
		std::cout << "a copy constructor called for a vector..." << std::endl;
		size = v.size;
		arr = new double[size];
		for (int i = 0; i < size; i++)
			arr[i] = 0.0;
	}

	// move constructor
	// takes as a parameter an rvalue

	Vector(Vector &&v)				
	{		
		std::cout << "move constructor called" << std::endl;								
		size = v.size;
		arr = v.arr;
		v.arr = nullptr;
	}
};

Vector	create_vector(void)
{
	return  (Vector(5));
}

void	take_vector(Vector v)
{

}

void	take_vec_by_ref(Vector &v)
{

}

int		main(void)
{
	int a;

	a = 5;
	print_nb(a);								// print_nb(int &i) will be called
	print_nb(1914);								// print_nb(int &&i) will be called

	Vector 	reusable = create_vector();
	take_vector(reusable);						// copy constructor will be called
	take_vec_by_ref(reusable);					// will not call any constructor
	take_vector(std::move(reusable));			// move constructor will be called, arr == nullptr
	return (0);
}
#include <iostream>

// a class that represents a vector of double values

/*
	Referene Collapsing rules

	1. T& & 	-> T&
	2. T& && 	-> T&
	3. T&& &	-> T&
	4. T&& &&	-> T&&
*/

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

/*
	1. No costly and unnecessary copy construction of Vector
	2. rvalue is forwarded as rvalue, and lvalue is forwarded as lvalue
*/

// universal reference, it can take both rvalue, lvalue, const, non-cons
// 1. T is a template type
// 2. type deduction happent to T

template<typename T>
void	relay(T &&arg)
{
	/*
		Returns an rvalue reference to arg if arg is not an lvalue reference.
		If arg is an lvalue reference, the function returns arg without modifying its type.
	*/

	take_vector(std::forward<T>(arg));
}

int		main(void)
{
	Vector 	reusable = create_vector();
	relay(reusable);
	relay(Vector(3));

	// removes a reference on type T

	std::remove_referene<int &>::type i;	// int i;
	return (0);
}
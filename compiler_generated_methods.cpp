#include <iostream>

/*
	1. default constructor(is geerated if no constructor is provided)
	2. copy constructor (is generated only if no 3,4,5,6 provided)
	3. coppy assignment operator (is generated only if 2,4,5,6 are not provided)
	4. destructor
	5. move constructor (is generated only if 2,3,4,6 are not provided)
	6. move assignment operator (is generated only if 2,3,4,5 are not provided)
*/

// 1, 2, 4 (2 is depricated)

class 	One 
{
	One &operator=(const &One) = delete;

	// will force a compiler to generate this method

	One(const One &) = default;			
};

// 3, 4 (4 is depricated)

class 	Two
{
	Two(const Two&) {}
};

// 4

class 	Three
{
	// move constructor

	Three(Three &&)
	{

	}
};

// 4

class 	Four
{
	// move constructor

	Four(Four &&) {}

	// default constructor

	Four(int i = 0) {}

	// copy constructor

	Four(const Four &, int i = 0)
	{
		
	}

};

int 	main(void)
{
	return (0);
}
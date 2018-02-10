#include <iostream>

// we have a class that has some interface

class 	Adaptee
{
public:
	void	do_something(void)
	{
		std::cout << "I am doing something (Adaptee) ... " << std::endl;
	}
};

// Now we want to use this interface in our class
// this code will cause an error
// we are trying to call a non-constant method in a const method

class 	TryAdapt : public Adaptee
{
public:
	void	process(void) const
	{
		/*
		 	do_something(); error		
		*/
	}
};

// This time we have the pointer to the Adaptee class, which interface we want to use
// that is why we have a constructor that takes Adaptee * as a parameter

class 	Adapter
{
private:
	Adaptee	*adpt;
public:
			Adapter(Adaptee *ad) : adpt(ad) {}
			~Adapter()
			{
				delete adpt;
			}
	void	process(void) const
	{
		adpt->do_something();
	}
};


int		main(void)
{
	Adapter	object(new Adaptee);

	object.process();
	return (0);
}
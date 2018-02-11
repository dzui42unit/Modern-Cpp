
#include "memory_class.hpp"

/* 
	default concstructor that allocates a memory for 10 elements
 	and sets its size to zero
*/

template<typename D>
MemoryClass<D>::MemoryClass()
{
	cont_size = 0;
	reserved = 10;
	data = new D[reserved];
}

/*
	a constructor that takes a number of elements as a parameter
	this number of elements will be allocated and the values set to the deafault values
*/

template<typename D>
MemoryClass<D>::MemoryClass(size_t nb) : reserved(nb), cont_size(nb)
{
	data = new D[reserved];
	for (int i = 0; i < reserved; i++)
		data[i] = D();

	/* D() = allows to call a default constructor for any type of data that will be passed */
}

/*
	copy constructor
*/

template<typename D>
MemoryClass<D>::MemoryClass(const MemoryClass &mem)
{
	int i;

	cont_size = mem.cont_size;
	reserved = mem.reserved;
	data = new D[reserved];
	for (i = 0; i < cont_size; i++)
		data[i] = mem.data[i];
}

/*
	copy assignment operator
*/

template<typename D>
MemoryClass<D> &MemoryClass<D>::operator=(const MemoryClass &mem)
{
	int i ;

	cont_size = mem.cont_size;
	reserved = mem.reserved;
	data = new D[reserved];
	for (i = 0; i < cont_size; i++)
		data[i] = mem.data[i];
	for (; i < reserved; i++)
		data[i] = D();
}

/*
	element access operator
*/


template<typename D>
D		&MemoryClass<D>::operator[](size_t i)
{
	if (i >= cont_size)
		throw(OutOfRange());
	return (data[i]);
}

/*
	returns a size of a container
*/

template<typename D>
size_t	MemoryClass<D>::size() const
{
	return (cont_size);
}

/*
	destructor that frees memory
*/

template<typename D>
MemoryClass<D>::~MemoryClass()
{
	delete []data;
}

/*
	returns an amount of reserved space in the container
*/

template<typename D>
size_t	MemoryClass<D>::reserved_space(void) const
{
	return (reserved);
}

/*
	adds a new element to the container
*/

template<typename D>
void	MemoryClass<D>::push_back(D el)
{
	if (cont_size < reserved)
	{
		data[cont_size] = el;
		cont_size++;
	}
	else
	{
		D 	*temp;

		temp = new D[cont_size];
		temp = std::move(data);
		reserved += 5;
		data = new D[reserved];
		data = std::move(temp);
		data[cont_size] = el;
		cont_size++;
	}
}

/*
	returns the last element from the memory
*/

template<typename D>
D 	MemoryClass<D>::back() const
{
	if (cont_size == 0)
		throw (BackException());
	return (data[cont_size - 1]);
}

/*
	pops the last element if the vector
*/

template<typename D>
void	MemoryClass<D>::pop(void)
{
	if (cont_size == 0)
		throw (PopException());
	else
	{
		data[cont_size].~D();
		cont_size--;
	}
}

/*
	compares object that was passed as a parameter and the last added to the memory
*/

template<typename D>
void	MemoryClass<D>::assert(const D &el) const
{
	if (data[cont_size - 1] != el)
		throw (AssertException());
}

/*
	prints all the content of the container
*/

template<typename D>
void	MemoryClass<D>::print_data(void) const
{
	for (int i = 0; i < cont_size; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

/*
	print data reserved
*/

template<typename D>
void	MemoryClass<D>::print_data_res(void) const
{
	for (int i = 0; i < reserved; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

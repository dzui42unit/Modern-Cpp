#ifndef MEMORY_CLASS_HPP
#define MEMORY_CLASS_HPP

#include <iostream>
#include <string>

template<typename D>
class 	MemoryClass
{
private:
	size_t	reserved;
	size_t	cont_size;
	D		*data;
public:
					MemoryClass();
					MemoryClass(size_t nb);
					MemoryClass(const MemoryClass &);
	MemoryClass 	&operator=(const MemoryClass &);
					~MemoryClass();
	D 				&operator[](size_t t);
	size_t			size() const;
	size_t			reserved_space(void) const;
	void			push_back(D el);
	void			print_data(void) const;
	void			print_data_res(void) const;
	void			pop(void);
	void			assert(const D &) const;
	D 				back() const;
	class 			OutOfRange : public std::exception
	{
	public:
		const char 	*what() const noexcept(true) override
		{
			return ("MemoryClass::operator[]() - out of range");
		}
	};
	class 			PopException : public std::exception
	{
	public:
		const char *what() const noexcept(true) override
		{
			return ("MemoryClass::pop() - pop on empty memory");
		}
	};
	class 			AssertException : public std::exception
	{
	public:
		const char *what() const noexcept(true) override
		{
			return ("MemoryClass::assert() exception: instruction is not true.");
		}
	};
	class 			BackException : public std::exception
	{
		const char *what() const noexcept(true) override
		{
			return ("MemoryClass::back() - back() on empty memory");
		}
	};
};

#include "memory_class.cpp"

#endif
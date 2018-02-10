#include <iostream>

class ConstMethodClass
{
private:
	int val;
public:
	ConstMethodClass(int v) : val(v) {}
	~ConstMethodClass() {}
	void	foo(void)
	{
		std::cout << "void foo(void); val = " << val << std::endl;
	}
	void	foo(void) const
	{
		std::cout << "void foo(void) const; val = " << val << std::endl;
	}
};

int		main(void)
{	
	// In this case it is forbidden to change data, that a pointer points to
	// creates a read only location in the memory
	// 	string_1[1] = 'E'; will cause an error
	// string_1 = "new string" is OK

	const char *string_1 = "const char *string_1";
	std::cout << string_1 << std::endl;
	string_1 = "reassigned string_1";
	std::cout << string_1 << std::endl;

	// In this case it is also forbidden to change data the pointer points to
	// string_2[3] = 'i' will cause an error
	// string_2 = "new string" is OK

	char const *string_2 = "char *const string_2";
	std::cout << string_2 << std::endl;

	// in this case it is forbidden to change the value of a pointer
	// string_3 = "new string" will cause an error
	// string_3[1] = 'b' is OK

	char * const string_3 = "char *const string_3";
	std::cout << string_3 << std::endl;

	// const and classes

	ConstMethodClass a(2);
	ConstMethodClass const b(3);

	// a.foo();			void foo() {} called
	// b.foo() const;	void foo() const {} called

	a.foo();
	b.foo();
	
	return (0);
}
#include <string>
#include <iostream>
#include <memory>

class	Test
{
private:
	std::string		name;
public:
	Test()
	{
		std::cout << "Empty test created" << std::endl;
		name = "Empty Test";
	}
	Test(std::string str) : name(str)
	{
		std::cout << "Test " << name << " created" << std::endl;
	}
	~Test()
	{
		std::cout << name << " " << name << " destroyed" << std::endl;
	}
	void	say(void) const
	{
		std::cout << "My name is " << name << std::endl;
	}
};

void	foo(void)
{
	// not exception safe code
	// 1. Test object is created
	// 2. the t1 object is created
	// the problem can be that the Test object can be created, but t1 not, it causes memory leak

	std::shared_ptr<Test> t1(new Test());

	{
		std::shared_ptr<Test> t2 = t1;
		std::cout << "number of objects pointing to t1 is " << t1.use_count() << std::endl;
	}

	std::cout << "number of objects pointing to t1 is " << t1.use_count() << std::endl;
	t1->say();
}

int main()
{
	foo();

	/*

		// example of a bad shared_ptr creation
		// a smart pointer should be assigned at the moment of its creation, RAW pointer should not be used
	
		Test *t = new Test("bad test");

		std::shared_ptr<Test>	bt1(t);
		std::shared_ptr<Test>	bt2(t);

		std::cout << "number of pointer pointing to bt1 " << bt1.use_count() << std::endl;
		std::cout << "number of pointer pointing to bt2 " << bt2.use_count() << std::endl;

		// this part of code causes problems
		// the t pointer will be freed two times, when the bt1 and bt2 objects will be destoyed

	*/

	// the better way is to use a std::make_shared<T>(params) function;
	// params - are the arguments of the constructor

	// make_shared<T> combines steps 1 and step 2 described upper
	// exception safe code

	std::shared_ptr<Test> good_ptr = std::make_shared<Test>();
	std::shared_ptr<Test> ptr = std::make_shared<Test>("GOOD BOY");

	good_ptr->say();
	(*ptr).say();

	// a ways of casting a pointer
	// static_pointer_cast
	// dynamic_pointer_cast
	// const_pointer_cast

	std::cin.get();
    return 0;
}


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
		std::cout << name << " destroyed" << std::endl;
	}
	void	say(void) const
	{
		std::cout << "My name is " << name << std::endl;
	}
};

// all this test function show the cases when the p1 pointer will be freed
// and the Test objects will be destroyed

void	test1(void)
{
	std::cout << "test1() called, just two shared_ptrs craeted" << std::endl;
	std::shared_ptr<Test>	p1 = std::make_shared<Test>("Test1");
	std::shared_ptr<Test>	p2 = std::make_shared<Test>("Test2");
}

void	test2(void)
{
	std::cout << std::endl;
	std::cout << "test2() called, p1 = p2" << std::endl;
	std::shared_ptr<Test>	p1 = std::make_shared<Test>("Test1");
	std::shared_ptr<Test>	p2 = std::make_shared<Test>("Test2");
	p1 = p2;
}

void	test3(void)
{
	std::cout << std::endl;
	std::cout << "test2() called, p1 = nullptr" << std::endl;
	std::shared_ptr<Test>	p1 = std::make_shared<Test>("Test1");
	std::shared_ptr<Test>	p2 = std::make_shared<Test>("Test2");
	p1 = nullptr;
}

void	test4(void)
{
	std::cout << std::endl;
	std::cout << "test2() called, p1.reset()" << std::endl;
	std::shared_ptr<Test>	p1 = std::make_shared<Test>("Test1");
	std::shared_ptr<Test>	p2 = std::make_shared<Test>("Test2");
	p1.reset();
}

void	foo(void)
{
	std::cout << std::endl;

	// It will use a default deleteter: delete operator

	std::shared_ptr<Test>	ptr1 = std::make_shared<Test>("FT");

	// this will use a user defined deleter

	std::shared_ptr<Test>	ptr2 = std::shared_ptr<Test>(new Test("ST"), [](Test *t) { std::cout << "user defined deleter "; delete t; });

	// this code will cause a memory leak, (abortion)
	// Test[1] and Test[2] will not be deleted
	// std::shared_ptr<Test>	ptr3(new Test[3]);
	// solution is to provide a user defined deleter

	std::shared_ptr<Test>	ptr4(new Test[3], [](Test *t) { delete[]t; });

	// get() returns a RAW pointer
	// 1. Test *p = ptr4.get(); delete p; -> undefined
	// 2. std::shared_ptr<Test> pt5(p); -> undefined
	// causes double free of an object

	ptr1.get();
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	foo();
	std::cin.get();
    return 0;
}


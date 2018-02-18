#include <iostream>
#include <memory>
#include <string>

class Test
{
private:
	std::string		name;
public:
	Test()
	{
		name = "NO NAME";
		std::cout << name << " object created" << std::endl;
	}
	Test(std::string n) : name(n)
	{
		std::cout << name << " object created" << std::endl;
	}
	~Test()
	{
		std::cout << name << " object is destroyed" << std::endl;
	}
};

void	test(void)
{
	std::unique_ptr<Test>	pd(new Test("Test1"));

	// release() gives up an ownership of the object and returns an RAW pointer
	// reset() sets the value of a pointer to a pointer (with no params) = nullptr;
	// unique_ptr can be moved

	Test *p = pd.release();
	if (!pd)
		std::cout << "pd is empty" << std::endl;
}

// automatically move semantics will be used

std::unique_ptr<Test>	get_test(void)
{
	std::unique_ptr<Test>	p(new Test("get_test"));
	return (p);
}


void	test2(void)
{
	std::unique_ptr<Test>	p1(new Test("T1"));
	std::unique_ptr<Test>	p2(new Test("T2"));

	// 1. Test1 is destroyed
	// 2. p1 becomes empty
	// 3. p2 owns Test1

	p2 = std::move(p1);
	std::unique_ptr<Test> p3 = get_test();

	// we do need wo specify custom deleter for unique_ptr

	std::unique_ptr<Test[]>	tests(new Test[3]);
}

int main()
{
	test();
	test2();
	std::cin.get();
    return 0;
}


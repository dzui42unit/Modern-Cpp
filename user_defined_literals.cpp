#include <iostream>

// user defined literals
// operator"" - is used for overloading of it

// restrictions: it can be used with following parameters
// 1. char const *
// 2. unsigned long long
// 3. long double
// 4. char const *, std::size_t
// 5. wchar_t const *, std::size_t
// 6. char16_t const *, std::size_t
// 7. char32_t const *, std::size_t
// the return value can have any type


// without keyword constexpr all the unit translations are performed at runtime
// with keyword consexpr all the unit translations are performed at compilation stage

constexpr long double operator"" _cm(long double val)
{
	return (val * 10);
}

constexpr long double operator"" _m(long double val)
{
	return (val * 1000);
}

constexpr long double operator"" _mm(long double val)
{
	return (val);
}

// user defined literal that gives an ability to take a char string, that represents a binary number
// and convert it to the decimal number

int		operator"" _bin(const char *str, size_t len)
{
	int res;

	res = 0;
	for (int i = 0; i < len; i++)
	{
		res = res << 1;
		if (str[i] == '1')
			res += 1;
	}
	return (res);
}

int		main(void)
{
	long double height1;

	height1 = 3.4_m;
	std::cout << "Height1 is: " << height1 << std::endl;
	std::cout << "Height2 is: " << height1 + 0.3_mm << std::endl;
	std::cout << "110"_bin << std::endl;
	return (0);
}
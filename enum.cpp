#include <iostream>

enum apples { green_apple, red_apple };
enum oranges { small_orange, big_orage };

// C++11 enum class

enum class apple { small_apple, big_apple };
enum class orange { green_orange, red_orange };

int		main(void)
{
	apples ap1 = green_apple;
	oranges or1 = small_orange;

	std::cout << "ap1 == or1 of the enum apples and oranges gives the result" << std::endl;
	if (ap1 == or1)
		std::cout << "green_apple and small_orange are the same ..." << std::endl;
	else
		std::cout << "green_apple and small_orange are not the same ..." << std::endl;

	apple a1 = apple::small_apple;
	orange o1 = orange::green_orange;

	// this code will give us an compilation error
	// because of absence of the overloader operator==() that can compare two classes
	// of apple and orange types

	if (a1 == o1)
		std::cout << "apple::small_apple and orange::green_orange are the same ..." << std::endl;
	else
		std::cout << "apple::small_apple and orange::green_orange are not the same ..." << std::endl;

	return (0);
}
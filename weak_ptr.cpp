#include <string>
#include <iostream>
#include <memory>

	// this class wil cause a memory leak
	// because I will have a cyclic reference
	// the shared_pinter will never leave a scope and will not be destroyed


	class DogLeaks
	{
	private:
		std::shared_ptr<DogLeaks>	ptr_friend;
		std::string					name;
	public:
		void	bark(void)
		{
			std::cout << "Dog " << name << " rules!" << std::endl;
		}
		DogLeaks(std::string n) : name(n)
		{
			std::cout << "Dog is created: " << name << std::endl;
		}
		~DogLeaks()
		{
			std::cout << "Dog " << name << " is destroyed!" << std::endl;
		}
		void	make_friend(std::shared_ptr<DogLeaks> f)
		{
			ptr_friend = f;
		}
		void	show_friend(void)
		{
			std::cout << "He is owned by " << ptr_friend.use_count() << " pointers" << std::endl;
		}
	};


	// the solution is a weak_ptr

	class Dog
	{
	private:
		std::weak_ptr<Dog>	ptr_friend;
		std::string					name;
	public:
		void	bark(void)
		{
			std::cout << "Dog " << name << " rules!" << std::endl;
		}
		Dog(std::string n) : name(n)
		{
			std::cout << "Dog is created: " << name << std::endl;
		}
		~Dog()
		{
			std::cout << "Dog " << name << " is destroyed!" << std::endl;
		}
		void	make_friend(std::shared_ptr<Dog> f)
		{
			ptr_friend = f;
		}
		void	show_friend(void)
		{
			std::cout << "He is owned by " << ptr_friend.use_count() << " pointers" << std::endl;
		}
	};


int main()
{
	{
		std::shared_ptr<DogLeaks> DL1(new DogLeaks("DL1"));
		std::shared_ptr<DogLeaks> DL2(new DogLeaks("DL2"));
		DL1->make_friend(DL2);
		DL2->make_friend(DL1);
		std::cin.get();
	}

	std::cout << "left scope ..." << std::endl;

	{
		std::shared_ptr<Dog> D1(new Dog("DL1"));
		std::shared_ptr<Dog> D2(new Dog("DL2"));
		D1->make_friend(D2);
		D2->make_friend(D1);
		std::cin.get();
	}

	std::cin.get();

    return 0;
}


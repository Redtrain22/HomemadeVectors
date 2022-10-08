#include <iostream>
#include "Vector.cpp"

int main()
{
	Vector<int> test = Vector<int>();

	for (int i = 0; i < 100; ++i)
	{
		std::cout << "Iter: " << i << std::endl;
		test.push(i + 1);
	}

	std::cout << test;

	Vector<bool> test2 = Vector<bool>();

	for (int i = 0; i < 100; ++i)
		test2.push(i % 2 == 0 ? true : false);

	test2.print();

	long tests[5] = {0};
	std::cout << tests[0];

	Vector<long> test3 = Vector<long>(10);

	for (int i = 0; i < 100; ++i)
		test3.push(i + 1000000000000);

	std::cout << test3;

	// When running make using a Vector with a string fails because of the std::to_string() call.
	// Vector<std::string> test4 = Vector<std::string>();

	// for (int i = 0; i < 100; ++i)
	// 	test4.push("Index " + std::to_string(i));

	// std::cout << test4;
}
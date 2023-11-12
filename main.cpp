#include <iostream>

#include "Vector.h"

int main()
{
	Vector<int> vec(5);
	
	for (int i = 0; i < 5; ++i) {
		vec.push_back(i);
	}
	for (int i = 0; i < 5; ++i) {
		std::cout << vec.at(i) << std::endl;
	}
	return 0;
}
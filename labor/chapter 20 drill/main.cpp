#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <iterator>

template<typename Container>
void print(const Container &cont)
{
	for( auto const &i : cont)
	{
		std::cout << i << " ";
	}
	std:: cout << std::endl;
}

template<typename T>
void increase(T &a, int n)
{
	for( auto &i : a)
	{
		i += n;
	}
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1 != e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}
	return f2;
}


int main()
{
	std::array<int, 10> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> v { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::list<int> l { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	std::cout << "Array:\n";
	print(arr);
	std::cout << "Vector:\n";
	print(v);
	std::cout << "List:\n";
	print(l);
	
	std::array<int, 10> arr2 = arr;
	std::vector<int> v2 = v;
	std::list<int> l2 = l;
	
	std::cout << "Array2:\n";
	print(arr2);
	std::cout << "Vector2:\n";
	print(v2);
	std::cout << "List2:\n";
	print(l2);
	
	std::cout << "Increased:\n";
	increase(arr, 2);
	print(arr);
	increase(v, 3);
	print(v);
	increase(l, 5);
	print(l);
	
	std::cout << "Copy_to_vec:\n";
	my_copy(arr.begin(), arr.end(), v.begin());
	print(v);
	std::cout << "Copy_to_arr:\n";
	my_copy(l.begin(), l.end(), arr.begin());
	print(arr);
	
	auto iter = std::find(v.begin(), v.end(), 3);
	auto position = std::distance(v.begin(), iter);
	(iter != v.end())
		? std::cout << "Position of 3: " << position << std::endl
		: std::cout << "Doesn't contain 3\n";
	
	auto iter2 = std::find(l.begin(), l.end(), 27);
	auto position2 = std::distance(l.begin(), iter2);
	(iter2 != l.end())
		? std::cout << "Position of 27: " << position2 << std::endl
		: std::cout << "Doesn't contain 27\n";
	return 0;
}

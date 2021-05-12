#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>

template<typename Container>
void print(const Container &cont)
{
	for( auto const &i : cont)
	{
		std::cout << i << " ";
	}
	std:: cout << std::endl;
}

struct Item
{
	std::string name;
	int iid;
	double value;
	Item()
	:
	name(),
	iid(0),
	value(0)
	{
	}
	Item(std::string n, int i, double v)
	:
	name(n),
	iid(i),
	value(v)
	{
	}
};

std::istream &operator>>(std::istream &is, Item &it)
{
	std::string name;
	int iid;
	double value;
	is >> name >> iid >> value;
	if(!is)
	{
		return is;
	}
	it = Item(name,iid,value);
	return is;
}

std::ostream& operator<<(std::ostream &os, const Item &it)
{
	return os << it.name << " " << it.iid << " " << it.value << std::endl;
}

struct comp_by_name
{
	bool operator()(const Item &a, Item &b)
	{
		return a.name < b.name;
	}
};

struct comp_by_iid
{
	bool operator()(const Item &a, Item &b)
	{
		return a.iid < b.iid;
	}
};

struct comp_by_value
{
	bool operator()(const Item &a, Item &b)
	{
		return a.value < b.value;
	}
};

struct Find_name
{
	std::string name;
	Find_name(std::string nn)
	:
	name(nn)
	{
	}
	bool operator()(Item &i)
	{
		return i.name == name;
	}
};

struct Find_iid
{
	int iid;
	Find_iid(int id)
	:
	iid(id)
	{
	}
	bool operator()(Item &i)
	{
		return i.iid = iid;
	}
};

void f1()
{
	std::vector<Item> vi;
	const std::string ifname = "in.txt";
	std::ifstream ifs(ifname);
	if(!ifs)
	{
		throw std::runtime_error("Can't open file!");
	}
	Item i;
	while(ifs >> i)
	{
		vi.insert(vi.end(), i);
	}
	std::cout << "Feltoltes:\n";
	print(vi);
	std::sort(vi.begin(), vi.end(), comp_by_name());
	std::cout << "Nevszerint:\n";
	print(vi);
	std::cout << "iid:\n";
	std::sort(vi.begin(), vi.end(), comp_by_iid());
	print(vi);
	std::cout << "value:\n";
	std::sort(vi.begin(), vi.end(), comp_by_value());
	print(vi);
	Item i1{"horse shoe", 99, 12.34};
	Item i2{"Canon S400", 9988, 499.99};
	vi.insert(vi.end(), i1);
	vi.insert(vi.end(), i2);
	std::cout << "after insert:\n";
	print(vi);
	vi.erase(
		std::find_if(vi.begin(), vi.end(), Find_name("horse shoe"))
	);
	vi.erase(
		std::find_if(vi.begin(), vi.end(), Find_name("Canon S400"))
	);
	std::cout << "After name erase:\n";
	print(vi);
	vi.erase(
		std::find_if(vi.begin(), vi.end(), Find_iid(754))
	);
	vi.erase(
		std::find_if(vi.begin(), vi.end(), Find_iid(2517))
	);
	std::cout << "After iid erase:\n";
	print(vi);
}

void f2()
{
	std::cout << "With list:\n";
	std::list<Item> li;
	const std::string ifname = "in.txt";
	std::ifstream ifs(ifname);
	if(!ifs)
	{
		throw std::runtime_error("Cannot open file!");
	}
	Item i;
	while(ifs >> i)
	{
		li.insert(li.end(), i);
	}
	std::cout << "Feltolve:\n";
	print(li);
	li.sort(comp_by_name());
	std::cout << "Nevszerint:\n";
	print(li);
	li.sort(comp_by_iid());
	std::cout << "iid:\n";
	print(li);
	li.sort(comp_by_value());
	std::cout << "value:\n";
	print(li);
	Item i1{"horse shoe", 99, 12.34};
	Item i2{"Canon S400", 9988, 499.99};
	li.insert(li.end(), i1);
	li.insert(li.end(), i2);
	std::cout << "After insert:\n";
	print(li);
	li.erase(
		std::find_if(li.begin(), li.end(), Find_name("horse shoe"))
	);
	li.erase(
		std::find_if(li.begin(), li.end(), Find_name("Canon S400"))
	);
	li.erase(
		std::find_if(li.begin(), li.end(), Find_iid(754))
	);
	li.erase(
		std::find_if(li.begin(), li.end(), Find_iid(2517))
	);
	std::cout << "After erase:\n";
	print(li);
}

int main()
{
	try
	{
		f1();
		f2();
		return 0;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "Something went wrong!" << std::endl;
	}
}

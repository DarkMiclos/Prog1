#include <iostream>
#include <map>
#include <numeric>

template<typename T, typename U>
void print(std::map<T,U> &m)
{
	for(auto &a : m)
	{
		std::cout << a.first << " " << a.second << std::endl;
	}
}

template<typename T, typename U>
void read(std::map<T, U> &m)
{
	T word;
	U x;
	for(int i = 0; i < 10; i++)
	{
		std::cin >> word >> x;
		m.insert(std::pair<T, U>(word, x));
	}
}

int main()
{
	std::cout << "map:\n";
	std::map<std::string,int> msi;
	msi["alma"] = 10;
	msi["körte"] = 15;
	msi["barack"] = 20;
	msi["narancs"] = 25;
	msi["eper"] = 30;
	msi["ok"] = 35;
	msi["ropi"] = 40;
	msi["mogyi"] = 45;
	msi["totyi"] = 50;
	msi["bogyi"] = 55;
	std::cout << "Feltoltve:\n";
	print(msi);
	msi.erase(msi.begin(), msi.end());
	std::cout << "Torolve:\n";
	print(msi);
	std::cout << "Adja meg az uj elemeket:\n";
	read(msi);
	std::cout << "Uj elemek:\n";
	print(msi);
	int sum = std::accumulate(msi.begin(), msi.end(), 0,
		[](int s, const std::pair<std::string,int> &m)
		{
			return s += m.second;
		}
		);
	std::cout << "Összeg: " << sum << std::endl;
	std::map<int, std::string> mis;
	for(auto it = msi.begin(); it != msi.end(); it++)
	{
		mis.insert(std::pair<int, std::string>((*it).second, (*it).first));
	}
	
	std::cout<< "mis:\n";
	print(mis);
}

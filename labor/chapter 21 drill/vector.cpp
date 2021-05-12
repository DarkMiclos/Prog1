#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

template<typename Container>
void print(const Container &cont)
{
	for( auto const &i : cont)
	{
		std::cout << i << " ";
	}
	std:: cout << std::endl;
}

struct Less_than
{
	double v;
	Less_than(double d)
	:
	v(d)
	{
	}
	bool operator()(double x)
	{
		return x < v;
	}
};

int main()
{
	std::vector<double> vd;
	const std::string ifname = "szamok.txt";
	std::ifstream ifs(ifname);
	if(!ifs)
	{
		throw std::runtime_error("No input file!\n");
	}
	double i;
	while(ifs >> i)
	{
		vd.insert(vd.end(), i);
	}
	print(vd);
	std::vector<int> vi(vd.size());
	std::copy(vd.begin(), vd.end(), vi.begin());
	std::cout << "Copied:\n";
	print(vi);
	std::cout << "Pairs:\n";
	double sum_vd = 0;
	double sum_vi = 0;
	for(int i = 0; i < vi.size(); ++i)
	{
		sum_vd += vd[i];
		sum_vi += vi[i];
		std::cout << vd[i] << " " << vi[i] << std::endl;
	}
	std::cout << "Vd sum: " << sum_vd << std::endl;
	std::cout << "Vi sum: " << sum_vi << std::endl;
	double diff = sum_vd - sum_vi;
	std::cout << "Difference: " << diff << std::endl;
	std::reverse(vd.begin(), vd.end());
	std::cout << "Reversed vd:\n";
	print(vd);
	double mean = sum_vd / vd.size();
	std::cout << "Mean: " << mean << std::endl;
	std::vector<double> vd2(vd.size());
	auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(mean));
	vd2.resize(std::distance(vd2.begin(), it));
	print(vd2);
	
	std::sort(vd.begin(), vd.end());
	print(vd);
	return 0;
}

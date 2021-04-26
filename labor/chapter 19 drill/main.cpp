#include <iostream>
#include <vector>
#include <string>

template<typename T>	// 1.
struct S
{
	S(T t_val)	// 2.
	:
	val(t_val)
	{
	}
	T& operator=(const T &t_val);	// 10.
	T& get();	// 5.
	const T& get() const;	// 11.
	void set(const T &t_val);	// 9.
private:
	T val;	// 7.
};

template<typename T> T& S<T>::operator=(const T& t_val)	// 10.
{
	val = t_val;
	return val;
}

template<typename T>	// 6.
T& S<T>::get()
{
	return val;
}

template<typename T>	// 11.
const T& S<T>::get() const
{
	return val;
}

template<typename T>	// 9.
void S<T>::set(const T &t_val)
{
	val = t_val;
}

template<typename T>	//12.
std::istream &operator>>(std::istream &is, S<T> &s_val)
{
	T v;
	is >> v;
	if (!is) return is;
	s_val = v;
	return is;
}

template<typename T> void read_val(T& v)	// 12.
{
	std::cin >> v;
}

int main()
{
	S<int> n(5);	// 3.
	S<char> c('c');
	S<double> d(3.3);
	S<std::string> s("LM");
	std::vector<int> v { 10, 20, 30};
	S<std::vector<int>> s_vi(v);
	
	/* 4.
	std::cout << n.val << std::endl;
	std::cout << c.val << std::endl;
	std::cout << d.val << std::endl;
	std::cout << s.val << std::endl;
	std::cout << s_vi.val[1] << std::endl;
	*/
	
	std::cout << "Get:\n";
	std::cout << n.get() << std::endl;	// 8.
	std::cout << c.get() << std::endl;
	std::cout << d.get() << std::endl;
	std::cout << s.get() << std::endl;
	for(int i = 0; i < s_vi.get().size(); ++i)
	{
		std::cout << s_vi.get()[i] << std::endl;
	}
	std::cout << "Set:\n";
	n.set(10);
	std::cout << n.get() << std::endl;
	n = 5;
	std::cout << n.get() << std::endl;
	
	std::cout << "Read_val_in:\n";
	read_val(n);	// 13.
	read_val(c);
	read_val(d);
	read_val(s);
	std::cout << "Read_val_out:\n";
	std::cout << n.get() << std::endl;
	std::cout << c.get() << std::endl;
	std::cout << d.get() << std::endl;
	std::cout << s.get() << std::endl;
	return 0;
}

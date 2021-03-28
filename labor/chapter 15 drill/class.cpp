#include <iostream>
#include <vector>
#include <string>

struct Person
{
	Person() = default;
	
	Person(std::string &&fn, std::string &&sn, int &&a)
	:
	firstName(std::move(fn)),
	secondName(std::move(sn)),
	age(std::move(a))
	{
		const std::string fullName = fn + " " + sn;
		const std::string illegal = ";:\"'[]*&^%$#@!";
		if(a < 0 || a > 150)
		{
			throw "Pls enter a valid age(0-150) or be a wizard";
			
		}
		for(int i = 0; i < fullName.size(); ++i)
		{
			for(int j = 0; j < illegal.size(); ++j)
			{
				if(fn[i] == illegal[j])
				{
					throw "Your name is illegal";
				}
			}
		}
	}
	
	std::string GetFirstName() const
	{
		return firstName;
	}
	
	std::string GetSecondName() const
	{
		return secondName;
	}
	
	int GetAge() const
	{
		return age;
	}
	
	private:
		std::string firstName;
		std::string secondName;
		int age;
};

std::istream &operator>>(std::istream &is, Person &p)
{
	std::string fn, sn;
	int a;	
	is >> fn >> sn >> a;
	if(!is) return is;
	p = Person(std::move(fn), std::move(sn), std::move(a));
	return is;
}

std::ostream &operator<<(std::ostream &os, const Person &p)
{
	return os << p.GetFirstName() << " " << p.GetSecondName() << " " << p.GetAge();
}

int main()
{
	try
	{
	/*Person p1;
	p1.name = "Goofy";
	p1.age = 63;
	std::cout << p1.name << p1.age << std::endl;

	std::cout << "Enter your name and age :c\n";
	Person p2;
	std::cin >> p2;
	std::cout << p2;
	return 0;
	*/
		Person p3;
		std::vector<Person> persons;
		while(std::cin >> p3)
		{
			persons.push_back(p3);
		}
		for(int i = 0; i < persons.size(); ++i)
		{
			std::cout << persons[i] << std::endl;
		}	
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "Something went wrong idk\n"; 
	}
}



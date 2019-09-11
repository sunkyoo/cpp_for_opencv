#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Person {
public:
	string name;
	int age;

	Person() : name(""), age(0) {}
	Person(string _name, int _age) : name(_name), age(_age) {}

	bool operator <(const Person &p) const {
		return this->age < p.age;
	}

	void print() {
		cout << name << ", " << age << endl;
	}
};

bool cmp_name_asc(const Person& a, const Person& b)
{
	return a.name < b.name;
}

class ComparePerson {
public:
	bool operator ()(const Person& p1, const Person& p2) const
	{
		return p1.name < p2.name;
	}
};

int main(void)
{
	[] {};		// 가장 간단한 형태의 람다 표현식
	[]() {};	// 비어있는 인자
	[] {}();	// 호출까지 수행

	[](double a) { cout << a * a << endl; } (3.0);

	vector<Person> v;
	v.push_back(Person("Emma", 20));
	v.push_back(Person("Ryan", 28));
	v.push_back(Person("Jane", 25));
	v.push_back(Person("Sam", 40));
	v.push_back(Person("William", 35));

//	sort(v.begin(), v.end(), cmp_name_asc);

//	sort(v.begin(), v.end(), ComparePerson());

	sort(v.begin(), v.end(), [](const Person& p1, const Person& p2) {
		return p1.name < p2.name;
		});

	for (Person& p : v)
		p.print();

	return 0;
}
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

bool cmp_age_desc(const Person& a, const Person& b)
{
	return a.age > b.age;
}

bool cmp_name_asc(const Person& a, const Person& b)
{
	return a.name < b.name;
}

int main()
{
	// Sort array of integers

	int num[] = {2, 4, 1, 5, 3};

	sort(num, num + 5);
//	sort(begin(num), end(num));
//	sort(num, num + 5, greater<int>());

	for (int n : num)
		cout << n << endl;

	// Sort vector of strings

	vector<string> fruits {"orange", "banana", "apple", "pear", "lemon"};

	sort(fruits.begin(), fruits.end());
//	sort(begin(fruits), end(fruits));
//	sort(fruits.begin(), fruits.end(), greater<string>());

	for (auto s : fruits)
		cout << s << endl;

	// Sort vector of user-defined objects

	vector<Person> students;
	students.push_back(Person("Emma", 20));
	students.push_back(Person("Ryan", 28));
	students.push_back(Person("Jane", 25));
	students.push_back(Person("Sam", 40));
	students.push_back(Person("William", 35));

	sort(students.begin(), students.end());
//	sort(begin(students), end(students));
//	sort(students.begin(), students.end(), cmp_age_desc);
//	sort(students.begin(), students.end(), cmp_name_asc);

	for (Person p : students)
		p.print();

	return 0;
}

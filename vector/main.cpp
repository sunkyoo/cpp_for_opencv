#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> func()
{
	vector<int> v {-10, -20};
	return v;
}

int main()
{
	vector<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;

	vector<string> b {"I", "love", "you"};
	b.push_back("!!!");

	for (int i = 0; i < b.size(); i++)
		cout << b[i] << endl;

	vector<int> c(a.begin(), a.begin() + 3);

	for (int i = 0; i < c.size(); i++)
		cout << c.at(i) << endl;

	a.clear();
	cout << "a.size: " << a.size() << endl;

	vector<int> d = func();

	for (int i = 0; i < d.size(); i++)
		cout << d[i] << endl;

	return 0;
}
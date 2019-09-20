#include <iostream>
#include <memory>

using namespace std;

class Rect {
public:
	Rect() { cout << "Rect constructor!" << endl; }
	~Rect() { cout << "Rect destructor!" << endl; }
	void draw() { cout << "Rect drawn!" << endl; }
};

template<typename T> class Ptr {
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) { cout << "Ptr constructor!" << endl; }
	~Ptr() { 
		cout << "Ptr destructor!" << endl;
		delete obj; 
	}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

shared_ptr<Rect> createRect()
{
	return shared_ptr<Rect>(new Rect());
}

int main()
{
	{
		Rect* p = new Rect;
		p->draw();
		// p is not deleted! memory leak!!
	}

	cout << endl;

	{
		Ptr<Rect> p = new Rect;
		p->draw();	// Compiler thinks it as (p.operator->())->draw();

		//Ptr<Rect> p2 = p; // error!
	}

	cout << endl;

	{
		shared_ptr<Rect> c1(new Rect);
		shared_ptr<Rect> c2 = c1;
		shared_ptr<Rect> c3 = createRect();
		c1->draw();
		c2->draw();
		c3->draw();
	}

	return 0;
}

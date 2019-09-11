#include <iostream>

class Point {
private:
	int x, y;

public:
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	Point operator + (const Point& p) {
		return Point(x + p.x, y + p.y);
	}

	Point operator + (int n) {
		return Point(x + n, y + n);
	}

	void print() {
		std::cout << "[" << x << ", " << y << "]" << std::endl;
	}

	friend Point operator + (int n, const Point& p);
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

inline Point operator + (int n, const Point& p)
{
	return Point(n + p.x, n + p.y);
}

inline std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "[" << p.x << ", " << p.y << "]";
	return os;
}

int main()
{
	Point a(10, 20);
	Point b(30, 40);
	Point c = a + b;  // a.operator+(b)
	Point d = a + 10; // a.operator+(10)
	Point e = 10 + a; // operator+(10, a)

	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
}
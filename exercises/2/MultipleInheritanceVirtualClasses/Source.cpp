//#include <iostream>
//#include "Cars.h"
////#include "CarsAbstract.h"
//
//int main() {
//	UpgradedCarNewDetails a("Aston Martin", 12, "F1 services", 4);
//	UpgradedCarNewDetails b;
//	a.print();
//
//	return 0;
//}

#include <iostream>
using namespace std;

class base1
{
public:
	base1(int a, double b = 0)
	{
		n = a; x = b;
		cout << "base1: " << n << ", " << x << endl;
	}
	base1(const base1& p)
	{
		n = p.n + 1;
		x = p.x + 2;
		cout << "base1(const base1&)\n";
		cout << "base1.n: " << n << endl
			<< "base1.x: " << x << endl;
	}
	base1& operator=(const base1& p)
	{
		cout << "base1::operator=()\n";
		if (this != &p)
		{
			n = p.n + 1;
			x = p.x + 1.5;
			cout << "base1.n: " << n << endl
				<< "base1.x: " << x << endl;
		}
		return *this;
	}
private:
	int n;
	double x;
};

class base2
{
public:
	base2(int a = 1, double b = 0)
	{
		n = a;
		x = b;
		cout << "base2: " << n << ", " << x << endl;
	}
private:
	int n;
	double x;
};

class base3
{
public:
	base3(int a = 2, double b = 0)
	{
		n = a;
		x = b;
		cout << "base3: " << n << ", " << x << endl;
	}
	base3(const base3& p)
	{
		n = p.n + 1;
		x = p.x + 1.5;
		cout << "base3(const base3&)\n";
		cout << "base3.n: " << n << endl
			<< "base3.x: " << x << endl;
	}
private:
	int n;
	double x;
};

class der : public base1, protected base3, base2
{
public:
	der(int x = 0, int y = 0, int z = 0) : base1(x),
		base2(y, z), base3(z, x), a(x + y)
	{
		n = z;
		m = x - y;
		cout << "der: " << n << ", " << m << endl;
	}
	der(const der& p) : base3(p), base1(p), a(p)
	{
		cout << "der(const der&)\n";
		n = p.n + 1;
		m = p.m + 1;
		cout << "der.n: " << n << endl
			<< "der.m: " << m << endl;
	}
private:
	int n, m;
	base1 a;
	base2 b;
	base3 c;
};

int main()
{
	der p, q(1, 2, 3);
	der r = p;
	p = q;
	return 0;
}

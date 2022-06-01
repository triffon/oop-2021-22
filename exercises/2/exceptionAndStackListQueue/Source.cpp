#include <iostream>
#include <exception>
#include <stack>
#include <queue>


struct my_exeption : public std::exception {
	const char* what() const  {
		return "3000 entered";
	}
};


void test() {

	throw 3;
}

int main() {

	int n;
	try
	{
		std::cin >> n;
		if (n == 3000) {
			throw my_exeption();
		}

		std::cout << 3 / n;
	}
	catch (const char* ex)
	{
		std::cout << ex;
	}
	catch (int ex)
	{
		std::cout << ex;
	}
	catch (std::exception& ex)
	{
		std::cout << "augbh";
	}
	catch (my_exeption & ex)
	{
		std::cout << ex.what();
	}
	catch (...)
	{
		std::cerr << "last hope";
	}


	try
	{
		test();
	}
	catch (const std::exception&)
	{
			
	}

	std::stack<int> st;
	std::queue<int> q;
	std::priority_queue<int> pq;

	return 0;
}
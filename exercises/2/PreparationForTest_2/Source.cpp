#include <iostream>
#include "Student.h"
#include "Classroom.h"
#include "Set.h"

int sum(int a, int b)
{
	return a + b;
}

int divide(int a, int b)
{
	return a / b;
}

void map(int& element)
{
	element *= 2;
}

void test() {

}

//void changeValue(void (*map)(int))
//{
//	for (int i = 0; i < 10;i++)
//	{
//		map(arr[i]);
//	}
//}

bool filter(int a)
{
	return a % 2 == 0;
}

bool filter2(int a)
{
	return a > 5;
}

bool highGrade(const Student& st)
{
	return st.getGrade() > 4;
}

bool oddFN(const Student& st)
{
	return st.getFacultyNumber() % 2 == 1;
}

int main() {
	//sum(3, 5);

	//int (*fncP)(int, int);

	//fncP = sum;

	//std::cout << fncP(4, 5);

	//fncP = divide;

	//std::cout << fncP(6, 3);

	void (*mapP)(int&);
	void (*testP)();

	mapP = map;

	int arr[10];
	for (int i = 0; i < 10;i++)
	{
		arr[i] = i;
	}
	//for (int i = 0; i < 10 ;i++)
	//{
	//	mapP(arr[i]);
	//}
	//for (int i = 0; i < 10;i++)
	//{
	//	std::cout << arr[i] << " ";
	//}
	
	bool (*predicate)(int);

	predicate = filter2;

	//for (int i = 0; i < 10;i++)
	//{
	//	if (predicate(arr[i]))
	//	{
	//		std::cout << arr[i];
	//	}
	//}

	Student st("If Antonov", 71875, "IS", 6, 245624);

	Student a;

	Classroom room;
	room.addStudent(st);
	room.addStudent(a);

	room.invite(oddFN);



	return 0;
}

bool mon(IntSet* set[], int n)
{
	bool flag = true;
	for (int i = 0; i < n-1;i++)
	{
		if (!(set[i] < set[i + 1]))
		{
			flag = false;
			break;
		}
	}
	return flag;
}
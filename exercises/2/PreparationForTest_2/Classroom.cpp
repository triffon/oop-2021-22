#include "Classroom.h"

void Classroom::copy(const Classroom& other)
{
	size = other.size;
	capacity = other.capacity;
	students = new Student[capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		students[i] = other.students[i];
	}
}

void Classroom::resize()
{
	capacity *= 2;
	Student* temp = new Student[capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = students[i];
	}
	delete[] students;
	students = temp;
}

Classroom::Classroom()
{
	capacity = 3;
	size = 0;
	students = new Student[capacity];
}

Classroom::Classroom(int capacity)
{
	if (capacity < 0)
	{
		this->capacity = 0;
	}
	else
	{
		this->capacity = capacity;
	}
	size = 0;
	students = new Student[this->capacity];
}

Classroom::Classroom(const Classroom& other)
{
	copy(other);
}

Classroom& Classroom::operator=(const Classroom& other)
{
	if (this != &other)
	{
		delete[] students;
		copy(other);
	}
	return *this;
}

Classroom::~Classroom()
{
	delete[] students;
}

void Classroom::addStudent(const Student& newStudent)
{
	if (size == capacity)
	{
		resize();
	}
	students[size++] = newStudent;
}

void Classroom::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		students[i].print();
	}
}

void Classroom::invite(predicate p) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (p(students[i]))
		{
			students[i].invite();
		}
	}
}

//void Classroom::sort(bool ascending)
//{
//	for (size_t i = 0; i < size - 1; i++)
//	{
//		for (size_t j = 0; j < size; j++)
//		{
//			if (ascending)
//			{
//				if (students[i].getFacultyNumber() > students[j].getFacultyNumber())
//				{
//					std::swap(students[i], students[j]);
//				}
//			}
//			else
//			{
//				if (students[i].getFacultyNumber() < students[j].getFacultyNumber())
//				{
//					std::swap(students[i], students[j]);
//				}
//			}
//		}
//	}
//}

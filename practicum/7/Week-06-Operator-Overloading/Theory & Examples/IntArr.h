#ifndef __INT_ARR_HEADER_DEFINED__
#define __INT_ARR_HEADER_DEFINED__

class IntArr {
public:
	IntArr();
	IntArr(const IntArr& other);
	IntArr& operator=(const IntArr& other);
	~IntArr();

	bool operator!() const; //Дали е празен

	IntArr& operator+=(int n); //Ще добавим ново число в масива
	IntArr& operator+=(const IntArr& rhs); //Ще слеем два масива
	
	IntArr& operator*=(int n); //Ще умножим по k всички числа в масива

	//Префиксно ++А
	IntArr& operator++(); //Ще увеличим всеки елемент с 1

	//Постфиксно А++
	IntArr& operator++(int n);

	int& operator[](size_t index); //Връщаме елемента на index

	friend bool operator==(const IntArr& lhs, const IntArr& rhs); // A == B
	friend bool operator!=(const IntArr& lhs, const IntArr& rhs); // A != B

	//Можем да си дефинираме каквото поведение ни е удобно, напр. дали сумата на единия е 
	//по-голяма от другия или пък дали всички елементи са по-големи
	friend bool operator>(const IntArr& lhs, const IntArr& rhs); // A > B
	friend bool operator>=(const IntArr& lhs, const IntArr& rhs); // A >= B

	void print() const;

private:
	void copy(const IntArr& other);
	void clear();
	void resize();

	size_t size;
	size_t capacity;
	int* arr;
};

//Някои оператори може да са външни и да не са приятели
IntArr operator+(const IntArr& lhs, int rhs);
IntArr operator+(const IntArr& lhs, const IntArr& rhs);
IntArr operator*(const IntArr& lhs, int rhs);


#endif //__INT_ARR_HEADER_DEFINED__

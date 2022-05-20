#pragma once

template<typename T>
class Relation {
private:
	T subject, object;
	char* action;
public:
	Relation(T s, T o, const char* a) : subject(s), object(o) {
		action = new char[strlen(a) + 1];
		strcpy_s(action, strlen(a) + 1, a);
	}
	//Relation(const Relation<T>& other);
	//Relation<T>& operator =(const Relation<T>& other);
	//~Relation();
	void print() const {
		std::cout << subject << ' ' << action << ' ' << object;
	}
	Relation<T> operator *(const Relation<T>& other) {
		if (object != other.subject) {
			return Relation<T>(*this);
		}
		char* res = new char[strlen(action) + 1 + strlen(", which is ") + strlen(other.action)];
		//strcpy strcat
		Relation<T> result(this->subject, other.object, res);
		delete[] res;
		return result;
	}
};
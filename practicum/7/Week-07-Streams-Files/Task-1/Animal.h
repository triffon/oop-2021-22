#pragma once
#include<cstring>
#include<fstream>
class Animal {
public:
	Animal(const char* name, const char* breed, size_t age) {
		copy(name, breed, age);
	}

	Animal(const Animal& other) {
		copy(other.name, other.breed, other.age);
	}

	Animal& operator=(const Animal& other) {
		if (this != &other) {
			clear();
			copy(other.name, other.breed, other.age);
		}

		return *this;
	}

	~Animal() {
		clear();
	}

	friend std::ostream& operator<<(std::ostream& os, const Animal& obj);
	friend std::istream& operator>>(std::istream& is, Animal& obj);

	//Binary
	void serialize(const char* filename) const {
		std::ofstream out(filename, std::ios::binary);

		if (!out)
			return;

		size_t size = strlen(name) + 1;
		out.write((const char*) &size, sizeof(size_t));
		out.write(name, size);

		size = strlen(breed) + 1;
		out.write((const char*) &size, sizeof(size_t));
		out.write(breed, size);

		out.write((const char*) &age, sizeof(size_t));

		out.close();
	}

	//Text
	void writeToTextFile(const char* filename) const {
		std::ofstream out(filename);

		if (!out)
			return;

		out << *this;

		out.close();
	}

private:
	void copy(const char* name, const char* breed, size_t age) {
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);

		len = strlen(breed) + 1;
		this->breed = new char[len];
		strcpy_s(this->breed, len, breed);

		this->age = age;
	}

	void clear() {
		delete[] name;
		name = nullptr;

		delete[] breed;
		breed = nullptr;
	}

	char* name;
	char* breed;
	size_t age;
};

std::ostream& operator<<(std::ostream& out, const Animal& obj) {
	out << obj.name << '\n' << obj.breed << '\n' << obj.age << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Animal& obj) {
	obj.clear();

	// Името може да е Gosho Pertov и породата ulichna prevuzhodna, т.е. трябва да използваме
	// getline - иначе ще четем само до спейса и името ще стане - Gosho, породата - Petrov и age ще гръмне
	char buffer[1024];
	in.getline(buffer, 1024); // взимаме името

	obj.name = new char[strlen(buffer) + 1];
	strcpy_s(obj.name, strlen(buffer) + 1, buffer);

	in.getline(buffer, 1024); // взимаме породата
	obj.breed = new char[strlen(buffer) + 1];
	strcpy_s(obj.breed, strlen(buffer) + 1, buffer);
	
	in >> obj.age;
	
	return in;
}
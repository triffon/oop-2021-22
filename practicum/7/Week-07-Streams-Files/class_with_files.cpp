#include<fstream>
#include<iostream>
#include<cstring>
class Dog {
public:
	Dog() :age(-1), name(nullptr), breed(nullptr) {};

	Dog(int age, const char* name, const char* breed)
		:age(age),
		name(new char[strlen(name) + 1]),
		breed(new char[strlen(breed) + 1])
	{
		strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->breed, strlen(breed) + 1, breed);
	}

	Dog(const Dog& other) {
		copy(other);
	}

	Dog& operator=(const Dog& other) {
		if (this != &other) {
			clear();
			copy(other);
		}

		return *this;
	}

	~Dog() {
		clear();
	}

	//Text mode
	void writeToFile(const char* filename) const {
		std::ofstream out(filename);

		if (!out)
			return;

		out << age << '\n';
		out << name << '\n';
		out << breed << '\n';

		out.close();
	}

	//Text mode
	void readFromFile(const char* filename) {
		// Тук е важно да знаем в какъв формат са записани данните във файла
		// и какво ще правим с тях
		
		std::ifstream in(filename);

		if (!in)
			return;

		// Ако само ще ги изведем на конзолата
		/*char buffer[1024];
		while (in.getline(buffer, 100)) {
			std::cout << buffer << ' ';
		}*/

		// Ако ще ги запазваме
		in >> age;
		in.get(); // новия ред след age

		char buffer[1024];
		in.getline(buffer, 1024); // взимаме името

		name = new char[strlen(buffer) + 1];
		strcpy_s(name, strlen(buffer) + 1, buffer);

		in.getline(buffer, 1024); // взимаме породата
		breed = new char[strlen(buffer) + 1];
		strcpy_s(breed, strlen(buffer) + 1, buffer);

		in.close();
	}

	//Binary mode
	void serialize(const char* filename) const {
		std::ofstream out(filename, std::ios::binary);

		if (!out)
			return;

		out.write((const char*)&age, sizeof(int));

		// It's an array so we have to save the size too!
		size_t size = strlen(name) + 1;
		out.write((const char*)&size, sizeof(size_t));
		out.write(name, size);


		size = strlen(breed) + 1;
		out.write((const char*)&size, sizeof(size_t));
		out.write(breed, size);

		out.close();
	}

	//Binary mode
	void deserialize(const char* filename) {
		if (age >= 0)
			return;

		std::ifstream in(filename, std::ios::binary);

		if (!in)
			return;

		in.read((char*)&age, sizeof(int));

		size_t size = 0;

		in.read((char*)&size, sizeof(size_t));
		name = new char[size];
		in.read(name, size);

		in.read((char*)&size, sizeof(size_t));
		breed = new char[size];
		in.read(breed, size);

		in.close();
	}

	void print() const {
		std::cout << age << " " << name << " " << breed << std::endl;
	}

private:
	void copy(const Dog& other) {
		age = other.age;
		
		name = new char[strlen(other.name) + 1];
		breed = new char[strlen(other.breed) + 1];
		
		strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->breed, strlen(breed) + 1, breed);
	}

	void clear() {
		delete[] name;
		name = nullptr;

		delete[] breed;
		breed = nullptr;
	}

	int age;
	char* name;
	char* breed;
};

int main() {

	Dog dog(12, "Charlie", "bulldog");

	dog.serialize("a_good_boy.dat");
	dog.writeToFile("text.txt");

	Dog doggo;

	doggo.readFromFile("text.txt");
	//doggo.deserialize("a_good_boy.dat");
	doggo.print();

	return 0;
}
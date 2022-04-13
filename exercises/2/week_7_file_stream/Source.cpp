#include <iostream>
#include <fstream>

int main() {
	int x = 43;
	std::ifstream in;
	std::ofstream out;

	//out.open("week_7_files.txt", std::ios::app);
	//if (out)
	//{
	//	//out.seekp(0, std::ios::end);
	//	out << "a" << " " << x;
	//}
	//out.close();
	//in.open("week_7_files.txt");
	//char* buffer = nullptr;
	//if (in)
	//{
	//	int size;
	//	in.seekg(0, std::ios::end);
	//	size = in.tellg();
	//	in.seekg(0, std::ios::beg);
	//	buffer = new char[size + 1];

	//	char c;

	//	//int i = 0;
	//	//while (!in.eof())
	//	//{
	//	//	in.get(c);
	//	//	buffer[i++] = c;
	//	//}
	//	in.read(buffer, size);
	//	buffer[size] = '\0';
	//	std::cout << buffer;
	//	//in.seekg(-4, std::ios::end);
	//	//std::cout << in.tellg();
	//	//in >> x;
	//	//std::cout << x;
	//	delete[] buffer;
	//}
	//in.close();


	//binary

	out.open("binaryFile.dat", std::ios::binary);
	if (out)
	{
		out.write((const char*)&x, sizeof(x));
	}
	out.close();
	in.open("binaryFile.dat", std::ios::binary);
	if (in)
	{
		in.read((char*)&x, sizeof(x));
		std::cout << in.tellg();
		std::cout << x;
	}
	in.close();

	return 0;
}
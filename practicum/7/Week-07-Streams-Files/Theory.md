# Потоци
- за вход и изход от стандартния командне прозорец (istream, ostream) - `#include <iostream>`
- за вход и изход от файлове - `#include <fstream>`
  - вход -> ifstream
  - изход -> ofstream

## Запазване на информация в тексов файл
- Първо трябва да създадем поток за записване във файл:
`std::ofstream outFile;`
- Посредством командата `open` с параметър пътя където да се създаде файла, отваряме файла за писане и ако не съществува го създаваме.
`outFile.open("myFile.txt");`
- Сега трябва да запишем информацията във файла. И **най-важното** да го затворим. (`outFile.close()`)

*ВАЖНО!* Не е необходимо файлът да съществува, с `open()` ще се създаде.

```cpp
int main()
{
  ofstream outFile;
  outFile.open("myfile.txt");
  char* line = new char[1000];
  cout << "Enter a line of text: ";
  getline(cin, line);
  outFile << line << endl;
  outFile.close();
  delete[] line;
  return 0;
}
```

## Четене на информация от текстов файл

- Първо създаваме `ifstream` обект, който ще използваме за работа с файла, от който ще четем.
`std::ifstream inFile;`
- Посредством командата `open` с параметър пътя където се намира файла (той трябва да съществува), отваряме файла за четене. *Обърнете внимание, че специалните символи в пътя като `\` трябва да бъдат escape-нати.*
`inFile.open("C:\\Users\\Admin\\Documents\\myFile.txt");`
- Вече можем да прочетем информацията от файла, като тук може да се въползваме от следното `while(fileName)` се изпълнява докато има данни във файла. И **най-важно** накрая да затворим файла (OS го прави за нас автоматично, но не си го пишете сами).

*ВАЖНО!* Не можем да четем от файл, който не съществува.

```cpp
#include <iostream>
#include <fstream>

int main()
{
  std::ifstream inFile;
  inFile.open("C:\\Users\\Admin\\Documents\\myFile.txt");
  char word[100];
  while (inFile) { 
    inFile.getline(word, 100);
    std::cout << word << std::endl;
  }
  inFile.close();
  return 0;
}
```
### По-кратък начин:
```cpp
#include <iostream>
#include <fstream>

int main()
{
  std::ifstream inFile;
  inFile.open("C:\\Users\\Admin\\Documents\\myFile.txt");
  char word[100];
  while (inFile.getline(word, 100)) {//Така или иначе като няма какво да се прочете getline ще върне false 
    std::cout << word << std::endl;
  }
  inFile.close();
  return 0;
}
```
### Различни режими за писане във файл:
Пишат се след пътя до файла по следния начин:
`outFile.open("myfile.txt", std::ios::trunc | std::ios::out); с | се прилагат няколко режима.` 
`inFile.open("myfile.txt", std::ios::in);`
1. ios::in - open file for input operation
2. ios::out - open file for output operation
3. ios::app - output appends at the end of the file.
4. ios::trunc - truncate the file and discard old contents.
5. ios::binary - for binary (raw byte) IO operation, instead of character-based.
6. ios::ate - position the file pointer "at the end" for input/output.

### Състояния на файла
Може да възникне проблем при отварянето или по време на работата с файл, за това има флагове, които обозначават тяхното състояние:
- good() - проверява дали състоянието на потока е добро
- eof() - проверява дали не сме стигнали края на файла
- fail() - проверява дали флаговете fail или bad са вдигнати
- bad() - проверява дали флагът bad e вдигнат  
- operator!() - връща вярно ако някое от предните две (fail/bad) е вярно   

За да може да работим с файла, той трябва да не е в лошо състояние:
```c++
if(!myFile)
    return; 

//или

while(myFile)
  //...
```

## Записване в бинарен файл (serialize)

- Първо трябва да отворим файла в бинарен режим с `std::ofstream out("C:\\Users\\Admin\\Documents\\myFile.txt", std::ios::binary);`

- Трябва да подадем указател към обекта, който записваме - ако имамем `char* str`, подаваме `str`, ако имаме `int age`, подаваме `(const char*) &age`. Когато обектът не е от тип `char*`, трябва да вземем указател към него (адреса му) и да го кастнем до `const char*`.

- При записване трябва да кажем какъв е размера на обекта, който записваме, например ако записваме `int` подаваме `sizeof(int)`, ако записваме низ - `strlen(str) + 1`.

- *ВАЖНО!* Преди да запишем масив, трябва да запишем и размера му, за да можем после да го прочетем от файла.   
```c++
int main() {
	int age = 5;
	const char* str = "Hello world!";

	std::ofstream out("Hello.dat", std::ios::binary);

	if (!out)
		std::cout << "Can't open file!\n";

  else{
	out.write((const char*)&age, sizeof(int));

	size_t size = strlen(str) + 1;
	out.write((const char*)&size, sizeof(size_t));
	out.write(str, size);

	out.close();
  }

	return 0;
}
```

## Четене от бинарен файл (deserialize)

- Както при писането отваряме в бинарен режим
- Подаваме указател към обекта, в който ще запишем данните, *но вече не е константен* - `char*`
- Подаваме размера на обекта, в който ще запишем данните - за тази стъпка беше важно при сериализиране да запазим и размера на масив!

```c++
int main() {
  int age;
  char* str = nullptr; 

	std::ifstream in(filename, std::ios::binary);

	if (!in)
		std::cout << "Can't open file!\n";

  else{
		in.read((char*)&age, sizeof(int));

		size_t size = 0;

		in.read((char*)&size, sizeof(size_t));
		str = new char[size];
		in.read(str, size);

		in.close();
  }
    
  return 0;
}
```

### Позиции за писане и четене (само върху бинарно отворени файлове)
- put ptr - сочи позицията за писане
- get ptr - сочи позицията за четене

- tellp(), tellg() - дават ни позицията, на която трябва да е следващия символ 
- seekp(streampos pos), seekg(streampos pos) - ние слагаме позицията, на която трябва да е следващия символ

Можем да кажем и откъде да броим позицията, която поставяме:
- ios_base::beg	- броим pos от началото на файла
- ios_base::cur	- броим pos от където се намираме в момента
- ios_base::end	- броим pos от края на стрийма

## Operator >> & << overloading
- винаги са приятелски функции за класа
```cpp
friend std::ostream& operator<<(std::ostream& os, const ClassName& obj);
friend std::istream& operator>>(std::istream& is, ClassName& obj);
```
- Връщаме `ostream&` или `istream&`, за да можем да правим `out << dog1 << dog2 <<...` и `in >> dog1 >> dog2 >>...`

```cpp
#include <iostream>
using namespace std;

class Date
{
    int mo, da, yr;
public:
    Date(int m, int d, int y)
    {
        mo = m; da = d; yr = y;
    }
    
    friend ostream& operator<<(ostream& os, const Date& dt);
    friend istream& operator>>(istream& os, const Date& dt);

};

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}

istream& operator>> (istream& is, Date& dt)
{
    is >> dt.mo>> dt.da>> dt.yr;
    return is;
}

int main()
{
    Date dt(5, 6, 92);
    cout << dt;
}
```
# Файлове - текстови и двоични

## Задача 1 :mirror:
Напишете програма, която отпечатва собствения си source code.

## Задача 2 :b::a::b::b::a: ... :a::b::a:
Напишете програма, която приема име на текстов файл от командния ред и отпечатва на екрана размера на файла в байтове. Помислете от какво зависи размерът на един файл. Ако такъв файл не съществува или не е подадено име на файл от командния ред, изведете подходящо съобщение.

## Задача 3 :eyes::sandwich:	
Реализирайте функция със следната сигнатура:
```c++
void replace(const char* fileName, const char* find, const char* replace);
```
която да замества всички срещания на думата `find` с думата `replace` в текстов файл с име `fileName`.

> Пример (извикваме функцията с параметри "princesa.txt", "princesa", "strandzhanka"):

Преди излълнение на програмата:
```
Prepechena filiq s kaima se naricha princesa i tova ne podlezhi na komentar.
Sinut na princesa Diana se kazva Harry.
Princ Karl i princesa Klara krali klarineti...
```
След излълнение на програмата:
```
Prepechena filiq s kaima se naricha strandzhanka i tova ne podlezhi na komentar.
Sinut na strandzhanka Diana se kazva Harry.
Princ Karl i strandzhanka Klara krali klarineti...
```

> Забележка: Всеки ред от файла трябва да завършва с точка

## Задача 4 :face_in_clouds:
Напишете програма, която приема име на бинарен файл от командния ред и отпечатва на екрана размера на файла в байтове. Помислете как бихте могли да направите това с помощта на `seek/tell` функциите. Ако такъв файл не съществува или не е подадено име на файл от командния ред, изведете подходящо съобщение.

## Задача 5 :lizard::ocean::fire:	
Напишете клас `Pokemon`, който се състои от:
- име (символен низ с най-много 50 символа)
- тип (изброим тип със следните възможности: NORMAL, FIRE, WATER, GRASS, ELECTRIC, GHOST, FLYING)
- сила (цяло положително число от 10 до 1000)

Не използвайте динамична памет, т.е. следвайте `Rule of 0`. 

Обектите от тип `Pokemon` трябва да са immutable, т.е. стойностите на техните член-данни се създават еднократно при създаването на обекта и след това не могат да се променят.

Създайте клас `PokemonHandler`, който има следния конструктор:
```c++
/**
 * @brief Construct a new PokemonHandler object
 * 
 * @param fileName a binary file name where the info about the Pokemons will be saved
 * @param pokemons an array of Pokemons
 * @param size size of the array of Pokemons
 */
PokemonHandler(const char* fileName, Pokemon* pokemons, std::size_t size);
```

Той трябва да запази информацията за подадения масив от Покемони в бинарен файл с име `fileName`.

Предефинирайте оператор `[]`, който приема индекс (цяло неотрицателно число) `i` и връща съответния Покемон на `i`-та позиция в бинарния файл `fileName`. Ако индексът е прекалено голям, изведете подходящо съобщение и върнете обект, конструиран по подразбиране.

### Бонус:
Пазете Покемоните във файла, сортирани по сила, и създайте метод `getBestPokemon`, който връща най-силния Покемон.

### :warning: Забележки

- Погрижете се за правилната работа с файлове, проверявайте за коректното отваряне на потоците и винаги ги затвярайте след употреба
- Целете се към максимално спазване на чист код
- Не е позволено използването на `std::string`
- Позволено е използването на библиотеките `<cstring>`, `<cassert>`, `<cstddef>` и `<fstream>`

COMPILER=g++
VERSION=-std=c++17
FLAGS=-Wall -Wextra -Werror -pedantic

output: main.o greeter.o world.o
	${COMPILER} main.o greeter.o world.o ${VERSION} ${FLAGS} -o output

main.o: main.cpp greeter.hpp
	${COMPILER} ${VERSION} ${FLAGS} -c main.cpp

greeter.o: greeter.hpp greeter.cpp world.hpp
	${COMPILER} ${VERSION} ${FLAGS} -c greeter.cpp

world.o: world.hpp world.cpp
	${COMPILER} ${VERSION} ${FLAGS} -c world.cpp

clean:
	rm *.o output

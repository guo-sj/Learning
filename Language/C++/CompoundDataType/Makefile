
cdt : main.o arrays.o pointers.o structures.o class.o
	g++ -o cdt main.o arrays.o pointers.o\
		structures.o class.o

main.o : main.cpp
	g++ -g -c main.cpp

arrays.o : arrays.cpp
	g++ -g -c arrays.cpp

pointers.o : pointers.cpp
	g++ -g -c pointers.cpp

structures.o : structures.cpp
	g++ -g -c structures.cpp

class.o : class.cpp
	g++ -g -c class.cpp

clean :
	rm cdt main.o arrays.o pointers.o \
		structures.o class.o

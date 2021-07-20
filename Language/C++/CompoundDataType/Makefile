
cdt : main.o arrays.o pointers.o structures.o
	g++ -o cdt main.o arrays.o pointers.o\
		structures.o

main.o : main.cpp
	g++ -g -c main.cpp

arrays.o : arrays.cpp
	g++ -g -c arrays.cpp

pointers.o : pointers.cpp
	g++ -g -c pointers.cpp

structures.o : structures.cpp
	g++ -g -c structures.cpp

clean :
	rm cdt main.o arrays.o pointers.o \
		structures.o *~ .*~

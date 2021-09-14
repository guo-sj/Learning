
sources = arrayOperation.c linkedListOperation.c main.c

objects = $(sources:.c=.o)

dsa : $(objects)
	cc -g3 -o $@ $^

arrayOperation.o : arrayOperation.c
	cc -g -c arrayOperation.c

linkedListOperation.o : linkedListOperation.c
	cc -g -c linkedListOperation.c

main.o : main.c
	cc -g -c main.c

clean:
	rm -f dsa $(objects)

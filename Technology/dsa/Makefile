
sources = basicOperation.c main.c

objects = $(sources:.c=.o)

dsa : $(objects)
	cc -g3 -o $@ $^

basicOperation.o : basicOperation.c
	cc -g -c basicOperation.c

main.o : main.c
	cc -g -c main.c

clean:
	rm -f dsa $(objects)

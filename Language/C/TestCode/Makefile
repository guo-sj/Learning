
sources = testcode.c testextern.c

objects = $(sources:.c=.o)

test : $(objects)
	cc -g3 -o $@ $^

testcode.o : testcode.c
	cc -g -c testcode.c

testextern.o : testextern.c
	cc -g -c testextern.c

clean:
	rm -f test $(objects)


sources = testcode.c testextern.c

objects = $(sources:.c=.o)

test : $(objects)
	cc -g -o $@ $^

%.o : %c
	cc -g -c -o $@ $<

clean:
	rm -f test $(objects)

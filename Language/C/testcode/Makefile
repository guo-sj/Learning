
sources = testcode.c testextern.c quickSort.c\
		  ch3.c ch4.c

objects = $(sources:.c=.o)

test : $(objects)
	cc -g3 -o $@ $^

testcode.o : testcode.c
	cc -g -c testcode.c

testextern.o : testextern.c
	cc -g -c testextern.c

quickSort.o : quickSort.c
	cc -g -c quickSort.c

ch3.o : ch3.c
	cc -g -c ch3.c

ch4.o : ch4.c
	cc -g -c ch4.c
clean:
	rm -f test $(objects) *~ .*~

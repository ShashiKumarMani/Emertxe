OBJ:=$(patsubst %.c,%.o,$(wildcard *.c))

a.out : $(OBJ)
	gcc -o $@ $^

clean :
	rm *.o *.out

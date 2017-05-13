CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -pthread
DEPS = monta.h resolve.h
OBJ = main.o monta.o resolve.o
%.o: %.c $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

exec: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

	rm -rf *.o

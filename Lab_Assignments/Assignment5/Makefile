CC=gcc
RM=rm -vf
all: q3_1 q3_2

q3_1: q3_1.c stack.c List.c
	$(CC) -o q3_1 q3_1.c stack.c List.c

q3_2: q3_2.c stack.c List.c
	$(CC) -o q3_2 q3_2.c stack.c List.c

.PHONY: clean
clean:
	$(RM) q3_1 q3_2

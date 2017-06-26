CC= gcc
RM= rm -vf
CFLAGS= -std=c99 -g
SRCDIR=Code
EXECDIR= executables
SRCFILES= q1.c q2.c q3.c
EXECPATH= $(patsubst %.c, $(EXECDIR)/%, $(SRCFILES))

$(EXECDIR):
	mkdir -p $(EXECDIR)

all: $(EXECPATH) $(EXECDIR)

$(EXECDIR)/q1: $(SRCDIR)/q1.c $(SRCDIR)/List.c $(SRCDIR)/SparseMatrix.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q1 $(SRCDIR)/q1.c $(SRCDIR)/List.c $(SRCDIR)/SparseMatrix.c -lm

$(EXECDIR)/q2: $(SRCDIR)/q2.c $(SRCDIR)/CList.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q2 $(SRCDIR)/q2.c $(SRCDIR)/CList.c -lm

$(EXECDIR)/q3: $(SRCDIR)/q3.c $(SRCDIR)/DList.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q3 $(SRCDIR)/q3.c $(SRCDIR)/DList.c -lm	

.PHONY: clean
clean:
	$(RM) $(EXECDIR)/~* $(EXECDIR)/q1 $(EXECDIR)/q2 $(EXECDIR)/q3

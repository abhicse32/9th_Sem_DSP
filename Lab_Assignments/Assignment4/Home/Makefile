CC= gcc
RM= rm -vf
CFLAGS= -lm -g
SRCDIR=CS12B032_HOME/Code
EXECDIR= executables
SRCFILES= q1.c q2.c q3.c
EXECPATH= $(patsubst %.c, $(EXECDIR)/%, $(SRCFILES))

all: $(EXECPATH) $(EXECDIR)

$(EXECDIR):
	mkdir -p $(EXECDIR)

$(EXECDIR)/q1: $(SRCDIR)/q1.c $(SRCDIR)/List.c $(SRCDIR)/SparseMatrix.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q1 $(SRCDIR)/q1.c $(SRCDIR)/List.c $(SRCDIR)/SparseMatrix.c

$(EXECDIR)/q2: $(SRCDIR)/q2.c $(SRCDIR)/CList.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q2 $(SRCDIR)/q2.c $(SRCDIR)/CList.c

$(EXECDIR)/q3: $(SRCDIR)/q3.c $(SRCDIR)/DList.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q3 $(SRCDIR)/q3.c $(SRCDIR)/DList.c	

.PHONY: clean
clean:
	$(RM) $(EXECDIR)/~* $(EXECDIR)/q1 $(EXECDIR)/q2 $(EXECDIR)/q3
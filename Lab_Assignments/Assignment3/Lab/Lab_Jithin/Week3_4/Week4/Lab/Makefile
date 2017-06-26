CC= gcc
RM= rm -vf
CFLAGS= -std=c99 -g
SRCDIR=Code
EXECDIR= executables
SRCFILES= q1.c q2.c
EXECPATH= $(patsubst %.c, $(EXECDIR)/%, $(SRCFILES))
$(EXECDIR):
	mkdir -p $(EXECDIR)

all: $(EXECPATH)

$(EXECDIR)/q1: $(SRCDIR)/q1.c $(SRCDIR)/List.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q1 $(SRCDIR)/q1.c $(SRCDIR)/List.c -lm

$(EXECDIR)/q2: $(SRCDIR)/q2.c $(SRCDIR)/Polynomial.c $(SRCDIR)/List.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q2 $(SRCDIR)/q2.c $(SRCDIR)/Polynomial.c $(SRCDIR)/List.c -lm

.PHONY: clean
clean:
	$(RM) $(EXECDIR)/~* $(EXECDIR)/q1 $(EXECDIR)/q2

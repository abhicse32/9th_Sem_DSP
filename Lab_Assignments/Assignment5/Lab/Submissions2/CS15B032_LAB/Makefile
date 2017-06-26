CC= g++
RM= rm -vf
CFLAGS= -lm -g -o 
SRCDIR=CS15B032_LAB/Code
EXECDIR= executables
SRCFILES= q1.c q2.c q3.c
EXECPATH= $(patsubst %.c, $(EXECDIR)/%, $(SRCFILES))
$(EXECDIR):
	mkdir -p $(EXECDIR)

all: $(EXECPATH)

$(EXECDIR)/q1: $(SRCDIR)/q1.c
	$(CC) $(CFLAGS) $(EXECDIR)/q1 $(SRCDIR)/q1.c

$(EXECDIR)/q2: $(SRCDIR)/q2.c
	$(CC) $(CFLAGS) $(EXECDIR)/q2 $(SRCDIR)/q2.c

$(EXECDIR)/q3: $(SRCDIR)/q3.c
	$(CC) $(CFLAGS) $(EXECDIR)/q3 $(SRCDIR)/q3.c

.PHONY: clean
clean:
	$(RM) $(EXECDIR)/*

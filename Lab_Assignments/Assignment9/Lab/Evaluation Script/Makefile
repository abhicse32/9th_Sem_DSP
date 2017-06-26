CC= gcc
RM= rm -vf
CFLAGS= -lm
SRCDIR=CS15B010_LAB/Code
EXECDIR= executables
SRCFILES= q1.c q2.c q3.c bst.c hash_map.c
EXECPATH= $(patsubst %.c, $(EXECDIR)/%, $(SRCFILES))

$(EXECDIR):
	mkdir -p $(EXECDIR)

all: $(EXECPATH)

$(EXECDIR)/q1: $(SRCDIR)/q1.c $(SRCDIR)/bst.c $(SRCDIR)/hash_map.c
		$(CC) $(CFLAGS) -o $(EXECDIR)/q1 $(SRCDIR)/q1.c $(SRCDIR)/bst.c $(SRCDIR)/hash_map.c
		
$(EXECDIR)/q2: $(SRCDIR)/q2.c $(SRCDIR)/bst.c $(SRCDIR)/hash_map.c
		$(CC) $(CFLAGS) -o $(EXECDIR)/q2 $(SRCDIR)/q2.c $(SRCDIR)/bst.c $(SRCDIR)/hash_map.c

$(EXECDIR)/q3: $(SRCDIR)/q3.c $(SRCDIR)/bst.c $(SRCDIR)/hash_map.c
		$(CC) $(CFLAGS) -o $(EXECDIR)/q3 $(SRCDIR)/q3.c $(SRCDIR)/bst.c $(SRCDIR)/hash_map.c

.PHONY: clean
clean:
	$(RM) -rf $(EXECDIR)/*

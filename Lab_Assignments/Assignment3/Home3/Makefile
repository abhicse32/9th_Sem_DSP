CC= gcc
RM= rm -vf
CFLAGS= -lm -g
SRCDIR=CS12B032_HOME/Code
EXECDIR= executables
SRCFILES= q1.c q2.c q3.c
EXECPATH= $(patsubst %.c, $(EXECDIR)/%, $(SRCFILES))
$(EXECDIR):
	mkdir -p $(EXECDIR)

all: $(EXECPATH)

$(EXECDIR)/q1: $(SRCDIR)/q1.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q1 $(SRCDIR)/q1.c

$(EXECDIR)/q2: $(SRCDIR)/q2.c $(SRCDIR)/q2_sort.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q2 $(SRCDIR)/q2.c $(SRCDIR)/q2_sort.c

$(EXECDIR)/q3: $(SRCDIR)/q3.c $(SRCDIR)/q2_sort.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q3 $(SRCDIR)/q3.c $(SRCDIR)/q2_sort.c

.PHONY: clean
clean:
	$(RM) $(EXECDIR)/q1 $(EXECDIR)/q2 $(EXECDIR)/q3 $(EXECPATH)/~*
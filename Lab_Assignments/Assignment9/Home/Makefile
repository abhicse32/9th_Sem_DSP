CC= gcc
RM= rm -vf
CFLAGS= -lm
SRCDIR=CS15B039_HOME/Code
EXECDIR= executables
SRCFILES= birthday.c driver_g.c driver.c graph.c set.c
EXECPATH= $(patsubst %.c, $(EXECDIR)/%, $(SRCFILES))

$(EXECDIR):
	mkdir -p $(EXECDIR)

all: $(EXECPATH)

$(EXECDIR)/driver: $(SRCDIR)/driver.c $(SRCDIR)/set.c $(SRCDIR)/graph.c
		$(CC) $(CFLAGS) -o $(EXECDIR)/driver $(SRCDIR)/driver.c $(SRCDIR)/set.c $(SRCDIR)/graph.c

$(EXECDIR)/driver_g: $(SRCDIR)/driver_g.c $(SRCDIR)/set.c $(SRCDIR)/graph.c
		$(CC) $(CFLAGS) -o $(EXECDIR)/driver_g $(SRCDIR)/driver_g.c $(SRCDIR)/set.c $(SRCDIR)/graph.c

$(EXECDIR)/birthday: $(SRCDIR)/birthday.c $(SRCDIR)/set.c $(SRCDIR)/graph.c
		$(CC) $(CFLAGS) -o $(EXECDIR)/birthday $(SRCDIR)/birthday.c $(SRCDIR)/set.c $(SRCDIR)/graph.c

.PHONY: clean
clean:
	$(RM) -rf $(EXECDIR)/*

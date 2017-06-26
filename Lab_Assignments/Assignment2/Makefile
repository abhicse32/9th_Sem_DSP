CC= gcc
RM= rm -vf
CFLAGS= -lm -g
EXECDIR=executables
SRCDIR=CS12B032_HOME
SRCFILES =$(basename $(notdir $@ $(wildcard $(SRCDIR)/hw*.c)))
EXECPATH=$(patsubst %, $(EXECDIR)/% ,$(SRCFILES))

$(EXECDIR):
	mkdir -p $(EXECDIR)
	
all: $(EXECPATH)

$(EXECDIR)/%: $(SRCDIR)/%.c
	-$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(EXECDIR)/*
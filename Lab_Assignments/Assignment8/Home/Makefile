CC= gcc
RM= rm -vf
CFLAGS= -lm -g
SRCDIR=CS12B032_HOME/Code
EXECDIR := executables 
DEPFILES= heap.c pq.c
DEPS= $(addprefix $(SRCDIR)/,$(DEPFILES))
SRCFILES= q1.c q2.c q3.c
EXECFILES := $(join $(addsuffix executables/,$(dir $(SRCFILES))), $(basename $(notdir $(SRCFILES))))
create_dir:
	mkdir -p $(EXECDIR)

all: create_dir $(EXECFILES)

.SECONDEXPANSION:
$(EXECFILES): $$(addsuffix .c,$$(subst executables/,$(SRCDIR)/,$$@))
	echo building $@ from $<
	-$(CC) -o $@ $<  $(DEPS) $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(EXECFILES)
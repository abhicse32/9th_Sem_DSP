CC= gcc
RM= rm -vf
CFLAGS= -lm -g
SRCDIR=CS15B020_LAB/Code
EXECDIR := executables 
# DEPFILES= List.c stack.c binary_tree.c
# DEPS= $(addprefix $(SRCDIR)/,$(DEPFILES))
SRCFILES= q1.c q2.c
EXECFILES := $(join $(addsuffix executables/,$(dir $(SRCFILES))), $(basename $(notdir $(SRCFILES))))
dir:
	mkdir -p $(EXECDIR)

all: dir $(EXECFILES)

.SECONDEXPANSION:
$(EXECFILES): $$(addsuffix .c,$$(subst executables/,$(SRCDIR)/,$$@))
	echo building $@ from $<
	-$(CC) -o $@ $<  $(DEPS) $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(EXECFILES)
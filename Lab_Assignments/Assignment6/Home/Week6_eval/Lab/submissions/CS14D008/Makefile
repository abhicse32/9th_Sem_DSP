CC= gcc
RM= rm -vf
CFLAGS= -lm -g -std=c99
SRCDIR=Code
EXECDIR := executables 
DEPFILES= List.c stack.c binary_tree.c queue.c
DEPS= $(addprefix $(SRCDIR)/,$(DEPFILES))
SRCFILES= q1.c q2.c
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

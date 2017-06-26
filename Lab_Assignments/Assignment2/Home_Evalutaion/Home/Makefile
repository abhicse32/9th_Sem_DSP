CC= gcc
RM= rm -vrf
CFLAGS= -lm -g
SRCFILES =$(wildcard */*.c)
SRCDIRS= $(wildcard */)
EXECFILES := $(join $(addsuffix executables/,$(dir $(SRCFILES))), $(basename $(notdir $(SRCFILES))))
EXECDIRS= $(SRCDIRS:%=%executables)

all: $(EXECDIRS) $(EXECFILES)

.SECONDEXPANSION:
$(EXECFILES): $$(addsuffix .c,$$(subst executables/,,$$@))
	echo building $@ from $<
	-$(CC) -o $@ $< $(CFLAGS)

$(EXECDIRS):
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) $(EXECFILES) $(EXECDIRS)
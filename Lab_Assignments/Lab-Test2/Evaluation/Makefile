CC= gcc
RM= rm -vrf
CFLAGS= -lm -g
SRCFILES =$(wildcard Submissions/*/*.c)
SRCDIRS= $(wildcard Submissions/*/)
EXECFILES := $(join $(addsuffix executables/,$(dir $(SRCFILES))), $(basename $(notdir $(SRCFILES))))
OUTDIRS := $(addsuffix outputs/,$(dir $(SRCDIRS)))
EXECDIRS= $(SRCDIRS:%=%executables)

all: $(EXECDIRS) $(OUTDIRS) $(EXECFILES)

.SECONDEXPANSION:
$(EXECFILES): $$(addsuffix .c,$$(subst executables/,,$$@))
	echo building $@ from $<
	-$(CC) -o $@ $< $(CFLAGS)

$(EXECDIRS):
	mkdir -p $@

$(OUTDIRS):
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) $(EXECFILES) $(EXECDIRS) $(OUTDIRS)
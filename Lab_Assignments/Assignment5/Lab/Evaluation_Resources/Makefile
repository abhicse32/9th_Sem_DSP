CC= gcc
RM= rm -vrf
CFLAGS= -lm -g
SRCFILES =$(wildcard Submissions/*/*/[q][1-3]*.c)
SRCDIRS= $(wildcard Submissions/*/Code/)
DEPS:= List.c stack.c
EXECFILES := $(join $(addsuffix executables/,$(dir $(SRCFILES))), $(basename $(notdir $(SRCFILES))))
OUTDIRS := $(addsuffix outputs/,$(SRCDIRS))
EXECDIRS= $(SRCDIRS:%=%executables)

all: $(EXECDIRS) $(OUTDIRS) $(EXECFILES)
	# echo $(DEPFILES)

.SECONDEXPANSION:
$(EXECFILES): $$(addsuffix .c,$$(subst executables/,,$$@))
	echo building $@ from $<
	-$(CC) -o $@ $(addprefix $(dir $<),$(DEPS)) $< $(CFLAGS)

$(EXECDIRS):
	mkdir -p $@

$(OUTDIRS):
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) $(EXECFILES) $(EXECDIRS) $(OUTDIRS)
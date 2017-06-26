CC= gcc
RM= rm -vrf
CFLAGS= -lm -g
SRCFILES =$(wildcard Submissions/*/*/[q][0-9]*.c)
SRCDIRS= $(wildcard Submissions/*/*/)
EXECFILES := $(join $(addsuffix executables/,$(dir $(SRCFILES))), $(basename $(notdir $(SRCFILES))))
DEPS:= List.c stack.c queue.c
# DEPS2:= List_3.c stack_3.c
DEPS2:= List.c stack.c
DEPS3:= stack_a.c queue_a.c
DEPS4:= List.c stack_using_queue.c queue.c
DEPS5:= List.c queue_using_stack.c stack.c
OUTDIRS := $(addsuffix outputs/,$(dir $(SRCDIRS)))
EXECDIRS= $(SRCDIRS:%=%executables)

all: $(EXECDIRS) $(OUTDIRS) $(EXECFILES)
	
.SECONDEXPANSION:
$(EXECFILES): $$(addsuffix .c,$$(subst executables/,,$$@))
	echo building $@ from $<
	if [ "$(notdir $@)" = "q1_stack" ] || [ "$(notdir $@)" = "q2_queue" ]; then \
		$(CC) -o $@ $(CFLAGS) $< $(addprefix $(dir $<),$(DEPS)); \
	elif [ "$(notdir $@)" = "q3_1" ] || [ "$(notdir $@)" = "q3_2" ]; then \
		$(CC) -o $@ $(CFLAGS) $< $(addprefix $(dir $<),$(DEPS2)); \
	elif [ "$(notdir $@)" = "q1_stack_a" ] || [ "$(notdir $@)" = "q2_queue_a" ]; then \
		$(CC) -o $@ $(CFLAGS) $< $(addprefix $(dir $<),$(DEPS3)); \
	elif [ "$(notdir $@)" = "q4_stack" ]; then \
		$(CC) -o $@ $(CFLAGS) $< $(addprefix $(dir $<),$(DEPS4)); \
	elif [ "$(notdir $@)" = "q4_queue" ];  then \
		$(CC) -o $@ $(CFLAGS) $< $(addprefix $(dir $<),$(DEPS5)); \
	fi;


$(EXECDIRS):
	mkdir -p $@

$(OUTDIRS):
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) $(EXECFILES) $(EXECDIRS) $(OUTDIRS)
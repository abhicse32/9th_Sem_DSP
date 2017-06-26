CC= gcc
RM= rm -vf
CFLAGS= -lm -g
SRCFILES = $(wildcard ./submissions/*/q2.c) #$(sort $(dir $(wildcard */)))
EXECFILES = $(patsubst %.c, %,$(SRCFILES)) 

all: $(EXECFILES)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	$(RM) $(EXECFILES)
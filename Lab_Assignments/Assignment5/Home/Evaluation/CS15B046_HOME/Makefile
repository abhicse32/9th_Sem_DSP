CC= gcc
RM= rm -vf
CFLAGS= -lm -g
SRCDIR=CS15B046_HOME/Code
EXECDIR= executables
SRCFILES= q1_stack_a.c q2_queue_a.c q2_queue.c q1_stack.c q3_1.c q3_2.c q4_stack.c q4_queue.c
EXECPATH= $(patsubst %.c, $(EXECDIR)/%, $(SRCFILES))
$(EXECDIR):
	mkdir -p $(EXECDIR)

all: $(EXECPATH)

$(EXECDIR)/q1_stack: $(SRCDIR)/q1_stack.c $(SRCDIR)/List.c $(SRCDIR)/stack.c 
	$(CC) $(CFLAGS) -o $(EXECDIR)/q1_stack $(SRCDIR)/q1_stack.c $(SRCDIR)/List.c $(SRCDIR)/stack.c

$(EXECDIR)/q1_stack_a: $(SRCDIR)/q1_stack_a.c $(SRCDIR)/stack_a.c 
	$(CC) $(CFLAGS) -o $(EXECDIR)/q1_stack_a $(SRCDIR)/q1_stack_a.c $(SRCDIR)/stack_a.c

$(EXECDIR)/q2_queue: $(SRCDIR)/q2_queue.c $(SRCDIR)/List.c $(SRCDIR)/queue.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q2_queue $(SRCDIR)/q2_queue.c $(SRCDIR)/List.c $(SRCDIR)/queue.c

$(EXECDIR)/q2_queue_a: $(SRCDIR)/q2_queue_a.c $(SRCDIR)/queue_a.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q2_queue_a $(SRCDIR)/q2_queue_a.c $(SRCDIR)/queue_a.c 

$(EXECDIR)/q3_1: $(SRCDIR)/q3_1.c $(SRCDIR)/stack.c $(SRCDIR)/List.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q3_1 $(SRCDIR)/q3_1.c $(SRCDIR)/stack.c $(SRCDIR)/List.c

$(EXECDIR)/q3_2: $(SRCDIR)/q3_2.c $(SRCDIR)/stack.c $(SRCDIR)/List.c
	$(CC) $(CFLAGS) -o $(EXECDIR)/q3_2 $(SRCDIR)/q3_2.c $(SRCDIR)/stack.c $(SRCDIR)/List.c

$(EXECDIR)/q4_stack: $(SRCDIR)/q4_stack.c $(SRCDIR)/List.c $(SRCDIR)/queue.c $(SRCDIR)/stack_using_queue.c 
	$(CC) $(CFLAGS) -o $(EXECDIR)/q4_stack $(SRCDIR)/q4_stack.c $(SRCDIR)/List.c $(SRCDIR)/queue.c $(SRCDIR)/stack_using_queue.c

$(EXECDIR)/q4_queue: $(SRCDIR)/q4_queue.c $(SRCDIR)/List.c $(SRCDIR)/stack.c $(SRCDIR)/queue_using_stack.c 
	$(CC) $(CFLAGS) -o $(EXECDIR)/q4_queue $(SRCDIR)/q4_queue.c $(SRCDIR)/List.c $(SRCDIR)/stack.c $(SRCDIR)/queue_using_stack.c 

.PHONY: clean
clean:
	$(RM) $(EXECDIR)/*

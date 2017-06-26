CC= gcc
RM= rm -vf
CFLAGS= -lm -g
SRCDIR=CS12B032_HOME/Code
EXECDIR= executables
SRCFILES= q1_stack_a.c q2_queue_a.c q2_queue.c q1_stack.c
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

.PHONY: clean
clean:
	$(RM) $(EXECDIR)/*
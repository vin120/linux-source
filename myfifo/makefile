.SUFFIXES: .c .o
CC=gcc
SRCS1=readfifo.c
SRCS2=writefifo.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)

EXEC1=readfifo
EXEC2=writefifo


all:$(OBJS1) $(OBJS2)
	$(CC) -o $(EXEC1) $(OBJS1)
	$(CC) -o $(EXEC2) $(OBJS2)
	@echo "done."

.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	
	-rm -f core*
	-rm -f $(OBJS1)
	-rm -f $(OBJS2)


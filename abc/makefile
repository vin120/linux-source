.SUFFIXES: .c .o
CC=gcc

SRCS=abc.c

OBJS=$(SRCS:.c=.o)

EXEC=abc

all:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '----success----'
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
	
clean:
	rm -f $(OBJS)
	rm -f core*
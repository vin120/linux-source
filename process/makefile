.SUFFIXES: .c .o
CC=gcc

SRCS=process.c

OBJS=$(SRCS:.c=.o)

EXEC=process

all:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '---success----'
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f core*


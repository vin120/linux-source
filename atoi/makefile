.SUFFIXES: .c .o
CC=gcc

SRCS=atoi.c

OBJS=$(SRCS:.c=.o)

EXEC=atoi

all:$(OBJS)
	$(CC) -o $(EXEC)  $(OBJS)
	@echo '---success----'
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f core*


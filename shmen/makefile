.SUFFIXES: .c .o

CC=gcc
SRCS=shmem.c
OBJS=$(SRCS:.c=.o)

EXEC=sheme


all:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	-rm -f $(OBJS)
	-rm -f core*
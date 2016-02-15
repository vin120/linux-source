.SUFFIXES: .c .o

CC=gcc

SRCS=thread.c

OBJS=$(SRCS:.c=.o)

EXEC=thread

all:$(OBJS) 
	$(CC) -o $(EXEC) $(OBJS) -lpthread
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
	

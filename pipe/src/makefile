.SUFFIXES: .o .c

CC=gcc

SRCS=pipe.c

OBJS=$(SRCS:.c=.o)

EXEC=pipe

all:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo ". done ."
.c.o:
	$(CC) -Wall -g -o $@ -c $<
	
clean:
	-rm -f core*
	-rm -f $(OBJS)
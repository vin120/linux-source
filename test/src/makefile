.SUFFIXES: .o .c

CC=gcc

SRCS=a.c
OBJS=$(SRCS:.c=.o)

EXEC=a

all: $(OBJS)
	$(CC)  -o $(EXEC) $(SRCS) -L. -ltest
	@echo " done. have fun"
	
.c.o:
	$(CC) -Wall -g  -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f core*

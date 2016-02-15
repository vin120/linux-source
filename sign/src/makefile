.SUFFIXES: .c .o

CC=gcc

SRCS=sign.c

OBJS=$(SRCS:.c=.o)

EXEC=signd

all:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo "done."
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f core*
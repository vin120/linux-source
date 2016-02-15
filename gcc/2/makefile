
CC=gcc

SRCS=mycal.c

OBJS=$(SRCS:.c=.o)
EXEC=mycal

all:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '-------success------'

.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f $(EXEC)
	rm -f core*

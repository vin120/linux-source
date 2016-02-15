.SUFFEXIS: .c .o

CC=gcc

SRC1=com-daem.c
SRC2=writefifo.c

OBJS1=$(SRC1:.c=.o)
OBJS2=$(SRC2:.c=.o)

EXE1=daem
EXE2=writefifo

all:$(OBJS1) $(OBJS2)
	$(CC) -o $(EXE1) $(OBJS1)
	$(CC) -o $(EXE2) $(OBJS2)

.c.o:
	$(CC) -Wall -g -o $@ -c $<	

clean:
	rm -f core*
	rm -f $(OBJS1)
	rm -f $(OBJS2)

.SUFFIXES: .c .o

CC=gcc

SRCS1=sock.c
SRCS2=server.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)

EXE1=client
EXE2=server

all: $(OBJS1) $(OBJS2)
	$(CC) -o $(EXE1) $(OBJS1) -lpthread
	$(CC) -o $(EXE2) $(OBJS2) -lpthread
	@echo '----- build success -----' 
	
.c .o:
	$(CC) -Wall -g -o $@ -c $<
	
clean:
	-rm -f $(OBJS1) $(OBJS2)
	-rm -f $(EXE1)
	-rm -f $(EXE2)
.SUFFIXES:.c .o

CC=gcc
SRCS=hello.c\
		add.c

OBJS=$(SRCS:.c=.o)
EXEC=hello


start: $(OBJS) 
	$(CC) -o $(EXEC) $(OBJS) 
	@echo "-----success-----"



#$(OBJS):
#	$(CC) -o $(OBJS) -c $(SRCS)
.c.o:
	$(CC) -o $@ -c $<
# @ 关联的对应的文件名   <  关联之前的文件名
clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS)
	rm -f $(EXEC)

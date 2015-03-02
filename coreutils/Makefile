CC = gcc
CFLAGS = -I include 
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,bin/%,$(SRCS))

vpath version.c lib
ALL: $(OBJS)
	
uname:version.o uname.c
	$(CC) -o $@ $^ $(CFLAGS)
bin/%:version.o %.c
	$(CC) -o $@ $^ $(CFLAGS)

version.o:version.c
	$(CC) -c  $^ $(CFLAGS)

clean:
	rm $(OBJS) -f
#just for fun:)
love:clean

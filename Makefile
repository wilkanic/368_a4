WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFLAGS = -DTEST_COUNTWORD

SRCS = a4_main.c
OBJS = $(SRCS:%.c=%.o)


a4: $(OBJS) 
	$(GCC) $(TESTFLAGS) $(OBJS) -o a4

.c.o: 
	$(GCC) $(TESTFLAGS) -c $*.c 

clean:
	rm -f a4 *.o output* *~
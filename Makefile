CC=gcc
CFLAGS=-g -Wall

SRCS=LinkedList.c
OBJS=LinkedList.o

TEST_SRCS=TestLinkedList.c CuTest.c AllTests.c
TEST_OBJS=TestLinkedList.o CuTest.o AllTests.o

TARGETS=test

test:
	$(CC) $(CFLAGS) $(SRCS) $(TEST_SRCS) -o test

clean:
	rm -f *.o $(TARGETS)
	rm -rf *.dSYM


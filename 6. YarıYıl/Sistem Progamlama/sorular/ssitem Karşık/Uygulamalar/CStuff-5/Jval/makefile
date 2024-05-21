# If you want to use this on your own machine, change CLASSDIR and/or INCLUDE and LIBS so
# that they point to the correct directories/library.

CLASSDIR = ../Libfdr
INCLUDE = -I$(CLASSDIR)/include
CFLAGS = $(INCLUDE)
LIBS = $(CLASSDIR)/lib/libfdr.a

EXECUTABLES = bin/jval_ex2 bin/simple_jval bin/badavg bin/goodavg
CC = gcc

all: $(EXECUTABLES)

clean:
	rm -f bin/*

bin/jval_ex2: src/jval_ex2.c
	$(CC) $(CFLAGS) -o bin/jval_ex2 src/jval_ex2.c $(LIBS)

bin/simple_jval: src/simple_jval.c
	$(CC) $(CFLAGS) -o bin/simple_jval src/simple_jval.c $(LIBS)

bin/badavg: src/badavg.c
	$(CC) $(CFLAGS) -o bin/badavg src/badavg.c $(LIBS)

bin/goodavg: src/goodavg.c
	$(CC) $(CFLAGS) -o bin/goodavg src/goodavg.c


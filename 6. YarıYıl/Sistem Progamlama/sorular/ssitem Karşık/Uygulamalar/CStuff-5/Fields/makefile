# If you want to use this on your own machine, change CLASSDIR and/or INCLUDE and LIBS so
# that they point to the correct directories/library.

CLASSDIR = ../Libfdr
INCLUDE = -I$(CLASSDIR)/include
LIBS = $(CLASSDIR)/lib/libfdr.a
CC = gcc

EX  =  bin/printwords \
       bin/tailanyf \
       bin/pipetest \
       bin/tail10-bad \
       bin/tail10-bad-print \
       bin/tail10-memory-leak \
       bin/tail10-good

all: $(EX) 

clean: 
	rm -f bin/*

bin/pipetest: src/pipetest.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/pipetest src/pipetest.c $(LIBS)

bin/printwords: src/printwords.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/printwords src/printwords.c $(LIBS)

bin/tail10-good: src/tail10-good.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/tail10-good src/tail10-good.c $(LIBS)

bin/tail10-bad: src/tail10-bad.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/tail10-bad src/tail10-bad.c $(LIBS)

bin/tail10-bad-print: src/tail10-bad-print.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/tail10-bad-print src/tail10-bad-print.c $(LIBS)

bin/tail10-memory-leak: src/tail10-memory-leak.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/tail10-memory-leak src/tail10-memory-leak.c $(LIBS)

bin/goodword: src/goodword.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/goodword src/goodword.c $(LIBS)

bin/badword: src/badword.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/badword src/badword.c $(LIBS)

bin/tailanyf: src/tailanyf.c $(LIBS)
	$(CC) $(INCLUDE) -o bin/tailanyf src/tailanyf.c $(LIBS)



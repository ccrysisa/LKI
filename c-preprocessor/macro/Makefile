CC = gcc
SIZE = 100000

all: macro function

macro: base.c
	$(CC) -o macro base.c -DMACRO -g -DNAME=\"macro.log\"

function: base.c
	$(CC) -o function base.c -g -DNAME=\"func.log\"

test: macro function
	./macro $(SIZE)
	./function $(SIZE)

plot: test
	gnuplot plot.gp

clean: 
	rm *.log macro function runtime.png

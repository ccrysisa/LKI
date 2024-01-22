func: func.o
	gcc $< -o $@

ptr: ptr.o
	gcc $< -o $@

ptr2: ptr2.o
	gcc $< -o $@

%.o: %.c
	gcc -c $< -o $@

s: s.c
	gcc -o $@ -Og -g $<

a: a.c
	gcc -o $@ -Og -g $<

ap: ap.c
	gcc -o $@ -Og -g $<

argv: argv.c
	gcc -o $@ -g $<

put: put.c
	gcc -o $@ -g $< -Wall

.PHONY: clean
clean:
	rm -rf *.o func ptr ptr2 s a ap put *tmp*

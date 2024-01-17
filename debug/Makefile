test-stopwatch: test-stopwatch.c
	gcc -g $^ -o $@

test: test.c
	gcc -g $^ -o $@

.PHONY: clean
clean:
	@echo "Clean..."
	-rm test-stopwatch
	-rm test
	-rm *.o *.o.* *.out


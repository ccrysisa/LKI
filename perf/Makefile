perf_top_example: perf_top_example.o
	gcc $< -o $@

perf_top_while: perf_top_while.o
	gcc $< -o $@

perf_stat_cache_miss: perf_stat_cache_miss.o
	gcc $< -o $@

perf_record_example: perf_record_example.o
	gcc $< -o $@

%.o: %.c
	gcc -c $<

.PHONY: clean
clean:
	@rm -rf *.o
	@rm -rf perf_top_example perf_top_while perf_stat_cache_miss

CC ?= gcc
CFLAGS_common ?= -march=native -Ofast -Wall -std=gnu99

EXEC = iterative iterative_2 recursive
EXEC_TIME_OUTFILE = execution_time.txt
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

iterative_2: iterative_2.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

generate_test_str: generate_test_str.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run: CFLAGS_common += -DMEASURE_TIME
run: $(EXEC) generate_test_str
	@$(RM) $(EXEC_TIME_OUTFILE)
	@bash time_measure.sh $(EXEC_TIME_OUTFILE)

cache-misses: $(EXEC) generate_test_str
	bash cache_misses.sh

unit_test: $(EXEC)
	@bash unit_test.sh ./iterative
	@bash unit_test.sh ./iterative_2
	@bash unit_test.sh ./recursive

plot: $(EXEC_TIME_OUTFILE)
	gnuplot -persist plotTime.gp

clean:
	$(RM) $(EXEC) $(EXEC_TIME_OUTFILE) *.o perf.* generate_test_str

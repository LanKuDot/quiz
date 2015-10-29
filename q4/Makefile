CC ?= gcc
CFLAGS_common ?= -O3 -march=native -Wall -std=gnu99

EXEC = iterative recursive
EXEC_OUTPUT_FILE = execution_time.txt
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

run: $(EXEC)
	bash time_measure.sh $(EXEC_OUTPUT_FILE)

plot: $(EXEC_OUTPUT_FILE)
	gnuplot -persist plotTime.gp

unit_test: $(EXEC)
	@./iterative 10 10
	@./recursive 10 10

clean:
	$(RM) $(EXEC) $(EXEC_OUTPUT_FILE) *.o perf.*

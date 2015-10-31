CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -g

EXEC = iterative recursive
EXEC_TIME_OUTPUT = execution_time.txt
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

run: $(EXEC)
	@$(RM) $(EXEC_TIME_OUTPUT)
	@bash time_measure.sh $(EXEC_TIME_OUTPUT)

plot: $(EXEC_TIME_OUTPUT)
	gnuplot -persist plotTime.gp

clean:
	$(RM) $(EXEC) *.o perf.*

CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
TIME_MEASURE_FILE = output_
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

run: $(EXEC)
	bash time_measure.sh

clean:
	$(RM) $(EXEC) *.o perf.*

CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

run: iterative
	@echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	@perf stat -e cpu-cycles,instructions,cache-references,cache-misses ./iterative "ABDELMQRSTUXZbcdgjklmoqrsuvxz" "J"

unit_test_iterative: iterative
	bash unit_test.sh ./iterative

clean:
	$(RM) $(EXEC) *.o perf.*

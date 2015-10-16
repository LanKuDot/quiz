CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative iterative_2 recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

iterative_2: iterative_2.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c main.c

generate_test_str: generate_test_str.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run: iterative
	@echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	@perf stat -e cpu-cycles,instructions,cache-references,cache-misses ./iterative "ABDELMQRSTUXZbcdgjklmoqrsuvxz" "J"

unit_test: $(EXEC)
	@bash unit_test.sh ./iterative
	@bash unit_test.sh ./iterative_2

clean:
	$(RM) $(EXEC) *.o perf.* generate_test_str

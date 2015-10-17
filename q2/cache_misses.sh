# !/bin/bash

test_str=$( ./generate_test_str 50 )
echo "Test string: $test_str"
echo "Searching character: y"
echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
sudo perf stat -e cache-misses,cache-references ./iterative $test_str 'y'
echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
sudo perf stat -e cache-misses,cache-references ./iterative_2 $test_str 'y'
echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
sudo perf stat -e cache-misses,cache-references ./recursive $test_str 'y'

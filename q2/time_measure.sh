# !/bin/bash

# - $1 is the name of output file
# - This bash script run the string case which the string
#   is generated from generate_test_str.c with input value from 1 to 30,
# - The searching character of the testing case is worst case.
# - Generate the result file for gnuplot to plot the graph.

echo "Case	iterative	iterative_2	recursive" >> $1

for i in {1..50}
do
	echo "Case $i"
	test_str=$( ./generate_test_str $i )
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	execution_time_i=$( ./iterative $test_str 'y' | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p' )
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	execution_time_i2=$( ./iterative_2 $test_str 'y' | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p' )
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	execution_time_r=$( ./recursive $test_str 'y' | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p' )
	echo "$i	$execution_time_i	$execution_time_i2	$execution_time_r" >> $1
done

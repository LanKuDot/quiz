# !/bin/bash

# - $1 is the name of output file
# - The input interger length from 1 to 50 with range from -10 to 10.

echo "Case	iterative	recursive" >> $1

for i in {1..50}
do
	echo "Case $i"
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	execution_time_i=$( ./iterative $i 10 | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p' )
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	execution_time_r=$( ./recursive $i 10 | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p' )
	echo "$i	$execution_time_i	$execution_time_r" >> $1
done

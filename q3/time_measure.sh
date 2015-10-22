# !/bin/bash

# Run same case for 10 times
for i in {1..10}; do
	echo "<Case 1>"
	echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
	./iterative build_tree.txt | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p'
	echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
	./recursive build_tree.txt | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p'
	echo "<Case 2>"
	echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
	./iterative build_tree_2.txt | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p'
	echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
	./recursive build_tree_2.txt | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p'
	echo "<Case 3>"
	echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
	./iterative build_tree_3.txt | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p'
	echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
	./recursive build_tree_3.txt | sed -ne 's/^.*[^0-9]\([0-9]*\.[0-9]*\) sec.*$/\1/p'
done

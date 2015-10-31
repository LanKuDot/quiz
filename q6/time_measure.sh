#!/bin/bash

echo "<Case 1> 50, 1, 50"
echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
iter_time=$(./iterative 50 1 50 | sed -ne 's/^.*[^0-9]\([0.9]*\.[0-9]*\) sec.*$/\1/p')
echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
rcur_time=$(./recursive 50 1 50 | sed -ne 's/^.*[^0-9]\([0.9]*\.[0-9]*\) sec.*$/\1/p')
echo "Case1	$iter_time	$rcur_time" >> $1

echo "<Case 2> 50, 12, 25"
echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
iter_time=$(./iterative 50 12 25 | sed -ne 's/^.*[^0-9]\([0.9]*\.[0-9]*\) sec.*$/\1/p')
echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
rcur_time=$(./recursive 50 12 25 | sed -ne 's/^.*[^0-9]\([0.9]*\.[0-9]*\) sec.*$/\1/p')
echo "Case2	$iter_time	$rcur_time" >> $1

echo "<Case 3> 50, 1, 15"
echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
iter_time=$(./iterative 50 1 15 | sed -ne 's/^.*[^0-9]\([0.9]*\.[0-9]*\) sec.*$/\1/p')
echo "echo 1 > /proc/sys/vm//drop_caches" | sudo sh
rcur_time=$(./recursive 50 1 15 | sed -ne 's/^.*[^0-9]\([0.9]*\.[0-9]*\) sec.*$/\1/p')
echo "Case3	$iter_time	$rcur_time" >> $1

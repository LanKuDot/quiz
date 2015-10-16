# !/bin/bash

$1 "ABDELMQRSTUXZbcdgjklmoqrsuvxz" "J" | grep 'L' &> /dev/null
if [ $? == 0 ]; then
	echo "Case 1:Correct."
else
	echo "Case 1:Wrong."
fi

$1 "BFGHKLNOQUVWXZabcdiprtvw" "i" | grep 'p' &> /dev/null
if [ $? == 0 ]; then
	echo "Case 2:Correct."
else
	echo "Case 2:Wrong."
fi

$1 "BCEFGIKNRUVacefghjlmoqsxy" "" | grep 'B' &> /dev/null
if [ $? == 0 ]; then
	echo "Case 3:Correct."
else
	echo "Case 3:Wrong."
fi

$1 "" "Z" | grep '' &> /dev/null
if [ $? == 0 ]; then
	echo "Case 4:Correct."
else
	echo "Case 4:Wrong."
fi

$1 "" "" | grep '' &> /dev/null
if [ $? == 0 ]; then
	echo "Case 5:Correct."
else
	echo "Case 5:Wrong."
fi

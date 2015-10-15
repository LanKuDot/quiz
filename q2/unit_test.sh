# !/bin/bash

$1 "bcdgjklmoqrsuvxzABDELMQRSTUXZ" "J" | grep 'b' &> /dev/null
if [ $? == 0 ]; then
	echo "Case 1:Correct."
else
	echo "Case 1:Wrong."
fi

$1 "abcdiprtvwBFGHKLNOQUVWXZ" "i" | grep 'p' &> /dev/null
if [ $? == 0 ]; then
	echo "Case 2:Correct."
else
	echo "Case 2:Wrong."
fi

$1 "acefghjlmoqsxyBCEFGIKNRUV" "" | grep 'a' &> /dev/null
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

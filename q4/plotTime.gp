set style data linespoints
set grid
set title "maxSunArray"
set xlabel "Integer array length"
set ylabel "execution time(sec)"
plot "execution_time.txt" using 1:2 title "iterative", \
     "execution_time.txt" using 1:3 title "recursive"

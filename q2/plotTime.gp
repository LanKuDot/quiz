set style data linespoints
set grid
set title "smallest_character"
set xlabel "input value"
set ylabel "execution time(sec)"
set format y "%.3e"
plot "execution_time.txt" using 1:2 title "linear scan", \
     "execution_time.txt" using 1:3 title "binray search", \
     "execution_time.txt" using 1:4 title "recursive"

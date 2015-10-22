set style data histogram
set style histogram cluster gap 1
set style fill solid border -1
set title "flatten"
set yrange[0:0.000003]
plot "execution_time.txt" using 2:xtic(1) t "Iterative", \
     "" using 3:xtic(1) t "Recursive", \

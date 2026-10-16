set xlabel "t"
set ylabel "N/N0(t)"
set tics font ",18"
set xlabel font ",18"
set ylabel font ",18"
set key font ",18"
set title font ",18"

set log y
set title "Radioactive Decay simulation"
plot "decay.dat" using 1:2
replot exp(-x*0.01)

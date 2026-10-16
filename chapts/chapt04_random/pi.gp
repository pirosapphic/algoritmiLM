reset

set xlabel "x"
set ylabel "y"
set tics font ",18"
set xlabel font ",18"
set ylabel font ",18"
set key font ",18"
set title font ",18"

set title "Hit or miss for area of unitary circle"
plot "pi.dat"
set parametric
set trange[0:2*pi]
replot sin(t),cos(t)

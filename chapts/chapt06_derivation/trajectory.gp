clear

set title "Trajectory, a=10"
set xlabel "t"
set ylabel "x(t), v(t), a(t)"

plot   "trajectory.dat" using 1:2 with lines title "x(t)"
replot "trajectory.dat" using 1:3 with lines title "v(t)"
replot "trajectory.dat" using 1:4 with lines title "a(t)"

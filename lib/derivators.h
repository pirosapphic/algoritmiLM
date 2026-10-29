#ifndef derivators_h
#define derivators_h
#include<cmath>

double forwardDiff(double(*func)(double), double x, double h);
double backwardDiff(double(*func)(double), double x, double h);
double centralDiff(double(*func)(double), double x, double h);
double fourthOrderDiff(double(*func)(double), double x, double h);
double forwardSecondDer(double(*func)(double), double x, double h);
double backwardSecondDer(double(*func)(double), double x, double h);
double centralSecondDer(double(*func)(double), double x, double h);

#endif

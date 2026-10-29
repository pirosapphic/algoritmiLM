#ifndef derivators_h
#define derivators_h
#include<cmath>

double forwardFirstDer(double(*func)(double), double x, double h);
double backwardFirstDer(double(*func)(double), double x, double h);
double centralFirstDer(double(*func)(double), double x, double h);
double fourthOrderFirstDer(double(*func)(double), double x, double h);
double forwardSecondDer(double(*func)(double), double x, double h);
double backwardSecondDer(double(*func)(double), double x, double h);
double centralSecondDer(double(*func)(double), double x, double h);

#endif

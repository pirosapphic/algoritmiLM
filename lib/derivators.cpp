#include"derivators.h"

double forwardFirstDer(double (*func)(double), double x, double h){
    //computes the derivative of func at point x, with the forward difference
    //method
    double f1 = func(x+h);
    double f2 = func(x);
    return (double)(f1-f2)/h;
}

double backwardFirstDer(double (*func)(double), double x, double h){
    //computes the derivative of func at point x, with the forward difference
    //method
    double f1 = func(x);
    double f2 = func(x-h);
    return (double)(f1-f2)/h;
}

double centralFirstDer(double (*func)(double), double x, double h){
    //computes the derivative of func at point x, with the forward difference
    //method
    double f1 = func(x+h);
    double f2 = func(x-h);
    return (double)(f1-f2)/2./h;
}

double fourthOrderFirstDer(double (*func)(double), double x, double h){
    //computes the derivative of func at point x, with the forward difference
    //method
    double f1 = func(x-h-h);
    double f2 = func(x-h);
    double f3 = func(x+h);
    double f4 = func(x+h+h);
    return (double)(f1-8.*f2+8.*f3-f4)/12./h;
}

double forwardSecondDer(double(*func)(double), double x, double h){
    double f1 = func(x+h+h);
    double f2 = func(x+h);
    double f3 = func(x);
    return (double)(f1-2.*f2+f3)/h/h;
}

double backwardSecondDer(double(*func)(double), double x, double h){
    double f1 = func(x);
    double f2 = func(x-h);
    double f3 = func(x-h-h);
    return (double)(f1-2.*f2+f3)/h/h;
}

double centralSecondDer(double(*func)(double), double x, double h){
    double f1 = func(x+h);
    double f2 = func(x);
    double f3 = func(x-h);
    return (double)(f1-2.*f2+f3)/h/h;
}


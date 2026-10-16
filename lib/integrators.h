#ifndef integrators_h
#define integrators_h

#include<iostream>
#include<cmath>

double rectangleIntegrator(double (*func)(double), double a, double b, int N);

double trapezoidIntegrator(double (*func)(double), double a, double b, int N);

double simpsonIntegrator(double (*func)(double),double a, double b, int N);

double gaussianIntegrator(double (*func)(double),double a, double b, int N, int Ng);

double gaussianIntegrator2D(double (*func)(double,double),double ax,double bx,
        double ay, double by, int N, int Ng);

#endif

#ifndef integrators_h
#define integrators_h

double rectangle_rule(double (*func)(double), double a, double b, int N);

double trapezoid_rule(double (*func)(double), double a, double b, int N);

double simpson_rule(double (*func)(double),double a, double b, int N);

double GaussianIntegrator(double (*func)(double),double a, double b, int N, int Ng);

#endif

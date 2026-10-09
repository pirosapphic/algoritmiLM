#ifndef integrators_h
#define integrators_h

double RectangleIntegrator(double (*func)(double), double a, double b, int N);

double TrapezoidIntegrator(double (*func)(double), double a, double b, int N);

double SimpsonIntegrator(double (*func)(double),double a, double b, int N);

double GaussianIntegrator(double (*func)(double),double a, double b, int N, int Ng);

#endif

#ifndef root_finders_h
#define root_finders_h
#include<iostream>
#include<cmath>

int bisectionRoot(double (*func)(double), double a, double, double b, double tol,
        double& zero);
int regulaFalsi(double (*func)(double), double a, double b, double xtol,
        double ytol, double& zero);
int secantRoot(double (*func)(double), double a, double b, double xtol,
        double ytol, double& zero);
int newtonMethod(double (*func)(double), double (*d_func)(double), double a,
        double b, double xtol, double ytol, double& zero);
int multipleRoots(double (*func)(double), double a, double b, double N,
        int& Nroots, double* xL, double* xR);
#endif

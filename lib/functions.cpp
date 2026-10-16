#include"functions.h"

double gaussianFunction(double x, double mean, double sigma){
    return 1./sigma/sqrt(2*M_PI) * exp(-0.5*(x-mean)*(x-mean)/sigma/sigma);
};

double normalFunction(double x){
    return gaussianFunction(x, 0., 1.);
};

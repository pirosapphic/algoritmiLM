#include"functions.h"

double gaussianFunction(double x, double mean, double sigma){
    //Normalized gaussian function with mean = mean and std. dev = sigma
    return 1./sigma/sqrt(2*M_PI) * exp(-0.5*(x-mean)*(x-mean)/sigma/sigma);
};

double normalFunction(double x){
    //Z-function: normalized Gaussian with mean = 0 and std. dev = 1
    return gaussianFunction(x, 0., 1.);
};

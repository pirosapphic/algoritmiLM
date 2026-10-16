#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdlib.h>
#include<fstream>
#include"../../lib/functions.h"

int main(){
    //generating gaussian distributed points
    //with mean = 0, sigma = 0.5
    srand48(time(NULL));
    double xmin = -5.;              double xmax = 5.;
    double xlen = xmax-xmin;

    double mean = 0.;               double sigma = 0.5;
    double ymax = 1./sigma/sqrt(2.*M_PI); //exact maximum of the distribution
    int N = 1e5;
    std::ofstream data;
    data.open("gaussian.dat");
    data << "#Gaussian distribution"<<std::endl<<"#x  y"<<std::endl;
    for(int i = 0; i < N ; i++){
        double x = xlen*(drand48()-0.5);
        double y = drand48()*ymax;
        if ( y <= gaussianFunction(x,mean,sigma) ){
            data << x << "  "<< y << std::endl;
        }
    }
    data.close();
    return 0;
}


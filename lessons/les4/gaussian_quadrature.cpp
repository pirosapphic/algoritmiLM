#include<iostream>
#include<iomanip>
#include<cmath>
#include"integrators.h"

double f1(double);
double f2(double);

int main(){
    std::cout<<std::setiosflags(std::ios::scientific); //sets precision
    int Ns = 2;
    int N = 1;
    int Ng = 3;
    double a = 0; //extrema
    double b = 3;
    double simpson = SimpsonIntegrator(f1,a,b,Ns);
    double gauss = GaussianIntegrator(f1,a,b,N,Ng);
    std::cout<<"Integral of sqrt(1+x)"<<std::endl;
    std::cout << "Simpson: "<<simpson<<"\tGaussian: "<<gauss<<std::endl;
    a = -1;
    b = 5;
    simpson = SimpsonIntegrator(f2,a,b,Ns);
    gauss = GaussianIntegrator(f2,a,b,N,Ng);
    std::cout<<"Integral of polynomial"<<std::endl;
    std::cout << "Simpson: "<<simpson<<"\tGaussian: "<<gauss<<std::endl;
}

double f1(double x){
    return sqrt(1.+x);
}

double f2(double x){
    return 1.-x+2*x*x+0.5*x*x*x+0.25*x*x*x*x-0.125*x*x*x*x*x;
}


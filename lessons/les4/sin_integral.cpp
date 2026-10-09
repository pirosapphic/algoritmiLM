#include<iostream>
#include<iomanip>
#include<cmath>
#include"integrators.h"

double f1(double);

int main(){
    std::cout<<std::setiosflags(std::ios::scientific); //sets precision
    double X = 0.8;
    std::cout<<"Gaussian, N=1, Ng=3: Si(0.8) = "<<GaussianIntegrator(f1,0.,X,1,3)
             <<std::endl;
    for(int i = 1; i < 9; i*=2){
        std::cout<<"Trapezoidal, N="<<i<<": Si(0.8) = "
                 <<TrapezoidIntegrator(f1,0.,X,i)<<std::endl;
    }
    for(int i = 2; i < 9; i*=2){
        std::cout<<"Simpson, N="<<i<<": Si(0.8) = "
                 <<SimpsonIntegrator(f1,0.,X,i)<<std::endl;
    }
}



double f1(double x){
    if(x==0.) return 1.;
    else return sin(x)/x;
}

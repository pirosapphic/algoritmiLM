#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include"integrators.h"

double f1(double);

int main(){
    std::cout<<std::setiosflags(std::ios::scientific); //sets precision
    double dx = 0.01;
    double xmin = 0.;
    double xmax = 25.;
    int Npoints = (xmax-xmin)/dx;
    double N = 10; //number of intervals
    double Ng = 3; //number of gaussian points
    for(int i = 0; i < Npoints; i++){
        double y = GaussianIntegration(f1,xmin,xmin+i*dx,N,Ng);
}



double f1(double x){
    if(x==0.) return 1.;
    else return sin(x)/x;
}

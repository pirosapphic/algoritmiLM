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
    std::ofstream fdata;
    fdata.open("Si_plot.dat");
    fdata << "# Data for the plot of Si(x) in [0,25]"<<std::endl;
    for(int i = 0; i < Npoints; i++){
        double x = xmin+i*dx;
        double y = GaussianIntegrator(f1,xmin,x,N,Ng);
        fdata<< x << "  "<<y<<std::endl;
    }
    return 0;
}



double f1(double x){
    if(x==0.) return 1.;
    else return sin(x)/x;
}

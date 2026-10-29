#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include"../../lib/root_finders.h"

double pn(double);
double dpn(double);

int main(){
    std::cout<<std::setiosflags(std::ios::scientific); //sets precision
    double a = -5.;         double b = 0.;
    double xtol = 1e-8;    double ytol = -1e-8;
    double zero;


    std::cout << "BISECTION" <<std::endl<<std::endl;
    if(!bisectionRoot(pn,a,b,xtol,ytol,zero)){
        std::cout<<"Exited correctly!"<<std::endl;
    }
    std::cout << "The zero is in "<<zero<<std::endl<<std::endl;


    std::cout << "REGULA FALSI" <<std::endl<<std::endl;
    zero = 666.;
    if(!regulaFalsi(pn,a,b,xtol,ytol,zero)){
        std::cout<<"Exited correctly!"<<std::endl;
    }
    std::cout << "The zero is in "<<zero<<std::endl<<std::endl;


    std::cout << "SECANT" <<std::endl<<std::endl;
    zero =666.;
    if(!secantRoot(pn,a,b,xtol,ytol,zero)){
        std::cout<<"Exited correctly!"<<std::endl;
    }
    std::cout << "The zero is in "<<zero<<std::endl<<std::endl;

    std::cout << "NEWTON" <<std::endl<<std::endl;
    zero =666.;
    if(!newtonMethod(pn,dpn,a,b,xtol,ytol,zero)){
        std::cout<<"Exited correctly!"<<std::endl;
    }
    std::cout << "The zero is in "<<zero<<std::endl<<std::endl;
    return 0;
}

double pn(double x){
    const int n = 3; //degree of polynomial
    double a[n+1] = {5.,1.,-3.,1};//coeff. with INCREASING order
    double p = a[n];
    for(int i = n-1; i >= 0; i--){
        p = p*x + a[i];
    }
    return p;
}

double dpn(double x){
    const int n = 3; //degree of polynomial
    double a[n+1] = {5.,1.,-3.,1};//coeff. with INCREASING order
    double p = a[n];
    double dp = 0.;
    for(int i = n-1; i >= 0; i--){
        dp = dp*x + p;
        p = p*x + a[i];
    }
    return dp;
}

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include"../../lib/root_finders.h"

double f(double);
double df(double);
double g(double);
double h(double);
int main(){
    std::cout<<std::setiosflags(std::ios::scientific); //sets precision
    double a = -1.;         double b = 1.;
    double xtol = 1e-7;    double ytol = -1e-7;
    double zero;


    std::cout << "BISECTION" <<std::endl<<std::endl;
    if(!bisectionRoot(f,a,b,xtol,ytol,zero)){
        std::cout<<"Exited correctly!"<<std::endl;
    }
    std::cout << "The zero is in "<<zero<<std::endl<<std::endl;


    std::cout << "REGULA FALSI" <<std::endl<<std::endl;
    zero = 666.;
    if(!regulaFalsi(f,a,b,xtol,ytol,zero)){
        std::cout<<"Exited correctly!"<<std::endl;
    }
    std::cout << "The zero is in "<<zero<<std::endl<<std::endl;


    std::cout << "SECANT" <<std::endl<<std::endl;
    zero =666.;
    if(!secantRoot(f,a,b,xtol,ytol,zero)){
        std::cout<<"Exited correctly!"<<std::endl;
    }
    std::cout << "The zero is in "<<zero<<std::endl<<std::endl;

    std::cout << "NEWTON" <<std::endl<<std::endl;
    zero =666.;
    if(!newtonMethod(f,df,a,b,xtol,ytol,zero)){
        std::cout<<"Exited correctly!"<<std::endl;
    }
    std::cout << "The zero is in "<<zero<<std::endl<<std::endl;
    return 0;
}
double f(double x){
    return exp(-x)-x;
}
double df(double x){
    return -exp(-x)-1.;
}
double g(double x){
    return x;
}
double h(double x){
    return sin(x);
}

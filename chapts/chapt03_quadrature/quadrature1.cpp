#include<iostream>
#include<iomanip>
#include<cmath>
#include"../../lib/integrators.h"

double f1(double x){
    return exp(-x);
}
double f2(double x);
double f3(double x);
//to pass a function as an argument of a function use
//returntype (*func)(argtype)

int main(){
    std::cout<<std::setiosflags(std::ios::scientific); //sets precision
    double a = 0;
    double b = 1;
    int N = 4;
    double exact = 1.-std::exp(-1.);
    std::cout<<"The exact result of int_0^1(e^-x)dx is "<<
        exact<<std::endl;
    double result_rect = rectangleIntegrator(f1,a,b,N);
    std::cout<<"The result of int_0^1(e^-x)dx using the rectangle rule (N="<<N
        <<") is "<<result_rect<<std::endl;
    double result_trap = trapezoidIntegrator(f1,a,b,N);
    std::cout<<"The result of int_0^1(e^-x)dx using the trapezoidal rule (N=4)"
        <<"is "<<result_trap<<std::endl;
    double result_simp = simpsonIntegrator(f1,a,b,N);
    std::cout<<"The result of int_0^1(e^-x)dx using the simpson rule (N=4) is "
        <<result_simp<<std::endl;
    //now we test convergence

    std::cout<<std::endl<<"Convergence test, M is the number of intervals"<<
        " needed to achieve a tolerance of 1e-5"<<std::endl;
    
    int M;
    double I,I_0,err;
    double tol = 1e-5;

    I_0=0.;
    M=2;
    while(1){
        I = rectangleIntegrator(f1,a,b,M);
        err = fabs(I-I_0);
        if (err < tol) break;
        I_0=I;
        M*=2;
    }
    std::cout<<"Number of iterations for rectangular: "<<M<<std::endl;

    I_0=0.;
    M=2;
    while(1){
        I = trapezoidIntegrator(f1,a,b,M);
        err = fabs(I-I_0);
        if (err < tol) break;
        I_0=I;
        M*=2;
    }
    std::cout<<"Number of iterations for trapezoid: "<<M<<std::endl;

    I_0=0.;
    M=2;
    while(1){
        I = simpsonIntegrator(f1,a,b,M);
        err = fabs(I-I_0);
        if (err < tol) break;
        I_0=I;
        M*=2;
    }
    std::cout<<"Number of iterations for simpson: "<<M<<std::endl;
    return 0;
}

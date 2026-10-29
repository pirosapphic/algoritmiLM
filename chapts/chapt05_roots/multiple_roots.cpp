#include<iostream>
#include<iomanip>
#include<cmath>
#include"../../lib/root_finders.h"
//practice session 5
double f(double);
double df(double);
double pn(double);
double dpn(double);

int main(){
    std::cout<<std::setiosflags(std::ios::scientific); //sets precision
    double a = -10.;    double b = 10.;
    double xtol = 1.e-7; double ytol = -1.e-7;
    const int N = 10; //number of intervals to divide [a,b] into
                      //this is also the maximum number of zeroes that can
                      //be found
    int Nroots; //number of roots of f in [a,b]
    double xL[N]; //array of left boundaries of bracketing intervals
    double xR[N]; //array of right boundaries of bracketing intervals
    multipleRoots(f,a,b,N,Nroots,xL,xR); //performs bracketing
    double roots[Nroots]; //array of the roots
    for(int i = 0; i < Nroots; i++){
        newtonMethod(f,df,xL[i],xR[i],xtol,ytol,roots[i]);
    }
    for(int i = 0; i < Nroots; i++){
        std::cout << "Root "<<i+1<<" in "<<roots[i]<<std::endl;
    }
    return 0;
}







double pn(double x){
    const int n = 2; //degree of polynomial
    double a[n+1] = {1./3.,1./5.,1./100.};//coeff. with INCREASING order
    double p = a[n];
    for(int i = n-1; i >= 0; i--){
        p = p*x + a[i];
    }
    return p;
}

double dpn(double x){
    const int n = 2; //degree of polynomial
    double a[n+1] = {1./3.,1./5.,1./100.};//coeff. with INCREASING order
    double p = a[n];
    double dp = 0.;
    for(int i = n-1; i >= 0; i--){
        dp = dp*x + p;
        p = p*x + a[i];
    }
    return dp;
}

double f(double x){
    return sin(x) - pn(x);
}

double df(double x){
    return cos(x) - dpn(x);
}

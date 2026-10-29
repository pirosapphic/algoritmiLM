#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
#include"../../lib/root_finders.h"

int g_Leg_N = 7; //degree of the polynomial
double legN(double x);
double dlegN(double x);

int main(){
    std::cout << std::setprecision(12);
    double a = -1;  double b = 1;   //interval
    const int N = 2*g_Leg_N+1;      //the roots are exactly g_Leg_N, but are not
                                    //equally spaced.
    double xL[N];  double xR[N];
    int Nroots;
    multipleRoots(legN, a, b, N, Nroots, xL, xR);
    std::cout<<"Polynomial of degree "<< g_Leg_N <<", roots found "<<Nroots
        <<std::endl;
    double roots[Nroots];   double w[Nroots];   //Gaussian weights
    double xtol = 1e-7; double ytol = -1e-7;
    for(int i = 0; i < Nroots; i++){
        //bisectionRoot(legN,xL[i],xR[i],xtol,ytol, roots[i]);
        newtonMethod(legN, dlegN,xL[i],xR[i],xtol,ytol, roots[i]);
    }
    for(int i = 0; i < Nroots; i++){
        double der = dlegN(roots[i]);
        w[i] = (double)2./((1-roots[i]*roots[i])*der*der);
    }

    for(int i = 0; i < Nroots; i++){
        std::cout << "Root "<<i+1<<" = "<<roots[i]<<" weight = "<<w[i]<<std::endl;

    }
    std::cout << "Format for gaussianIntegrator(): "<<std::endl;
    for(int i = 0; i < Nroots; i++){
        std::cout << "xi["<<i<<"]="<<roots[i]<<";"<<std::endl;
    }
    for(int i = 0; i < Nroots; i++){
        std::cout << "wi["<<i<<"]="<<w[i]<<";"<<std::endl;
    }
    return 0;
}

double legN(double x){
    double p0 = 1.;
    double p1 = x;
    if ( g_Leg_N == 0) return p0;
    if ( g_Leg_N == 1) return p1;
    double pnew = 0.;
    for(int i = 2; i <= g_Leg_N; i++){
        pnew = (double)1./i * ( (2.*i-1.)*x*p1 - (i-1.)*p0 );
        p0 = p1;
        p1 = pnew;
    }
    return pnew;
}

double dlegN(double x){
    double p0 = 1.;
    double p1 = x;
    if ( g_Leg_N == 0 ) return 0;
    if ( g_Leg_N == 1 ) return 1.;
    double pnew = 0.;
    for(int i = 2; i <= g_Leg_N; i++){
        pnew = (double)1./i * ( (2.*i-1.)*x*p1 - (i-1.)*p0 );
        p0 = p1;
        p1 = pnew;
    } //this loop calculates pnew = P_n(x) and p1 = P_{n-1}(x)
    double dpn = (double) g_Leg_N/(x*x-1.)*(x*pnew - p0);
    return dpn;
}


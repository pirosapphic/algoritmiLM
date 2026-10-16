#include<iostream>
#include<iomanip>
#include<cmath>
#include"../../lib/integrators.h"

//int_{X Y}dydx f(x,y)= int_Y dy(int_X dx f(x,y))=int_X dx G(x)
//

double f2d1(double, double); 
double f2d2(double, double); 
int main(){
    std::cout<<std::setiosflags(std::ios::scientific); //sets precision
    double ax = -1; double bx = 1;
    double ay = -1; double by = 1;
    int N = 4;      int Ng = 3;
    double result = gaussianIntegrator2D(f2d1,ax,bx,ay,by,N,Ng);
    std::cout << "The result for the polynomial is "<<result<<
        ", the exact result is "<<412./45<<std::endl;
    // for f2d2, we fix Ng=4 AND we vary N so that the accuracy is 1e-5
    Ng=4;
    N=1;
    std::cout<<"We now compute Pi using the piecewise function and find the"
             <<" necessary number of intervals N"<<std::endl
             <<"(with Ng=4) to have an absolute error <= 1e-5."<<std::endl;
    double res,err;
    do{
        res = gaussianIntegrator2D(f2d2,ax,bx,ay,by,N,Ng);
        err = fabs(M_PI-res);
        N+=1;
    }
    while(err >=1e-5);
    std::cout<<"Result for N = "<<N<<", with error = "<<err<<std::endl;
    return 0;
}
double f2d1(double x, double y){
    //should be exact for Ng>=3
    return x*x*x*x*y*y + 2.*x*x*y*y - x*x*y + 2.;
}

double f2d2(double x, double y){
    if(sqrt(x*x+y*y)<=1) return 1;
    else return 0;
}

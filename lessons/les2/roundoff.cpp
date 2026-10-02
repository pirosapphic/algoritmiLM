#include<iostream>
#include<cmath>
#include<iomanip>
//sq(x^2+1)-x = x^2+1-x/sq(x^2+1)+x
int main(){
    std::cout<<"Approximation of sqrt(x^2+1)-x for large x"<<std::endl;
    float x = 10.;
    int n = 10;
    for(int i = 0; i < n; i++){
        std::cout<<std::setprecision(14)<<"x = "<<x;
        std::cout<<"\tdirect: ";
        std::cout<<sqrt(x*x+1)-x;
        std::cout<<"\tration.: ";
        std::cout<< 1./(sqrt(x*x+1)+x);
        //std::cout<<std::endl;
        std::cout<<"\ttaylor (2nd): ";
        std::cout<< 0.5/x;
        std::cout<<std::endl;
        x = x*10.;
    }
    std::cout<<"Approximation of 1-cos(y) for small y"<<std::endl;
    float y = 1.000000000;
    int m = 10;
    for(int i = 0; i < m; i++){
        std::cout<<std::setprecision(14)<<"y = "<<y;
        std::cout<<"\tdirect: ";
        std::cout<<1.-cos(y);
        std::cout<<"\tration.: ";
        std::cout<< sin(y)*sin(y)/(1+cos(y));
        //std::cout<<std::endl;
        std::cout<<"\ttaylor (2nd): ";
        std::cout<< y*y/2.-y*y*y*y/(2.*3.*4.);
        std::cout<<std::endl;
        y = y/10.;
    }
    return 0;
}


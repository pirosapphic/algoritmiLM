#include<iostream>
#include<iomanip>
//machine precision is the value of \epsilon so that
//1+\epsilon = 1
// \forall n != 2^m, with m in N
int main(){
    double eps = 2.;
    double n = 1.0000000;
    while(n+eps != n){
        eps = eps/2.;
    }
    std::cout<<"The machine precision for double is "<<std::setprecision(14)<<eps
        <<std::endl;
    float eps_f = 2.;
    float n_f = 1.0000000;
    while(n_f+eps_f != n_f){
        eps_f = eps_f/2.;
    }
    std::cout<<"The machine precision for float is "<<std::setprecision(14)<<eps_f
        <<std::endl;
    long double eps_ld = 2.;
    long double n_ld = 1.0000000;
    while(n_ld+eps_ld != n_ld){
        eps_ld = eps_ld/2.;
    }
    std::cout<<"The machine precision for long double is "<<std::setprecision(14)
        <<eps_ld<<std::endl;
    return 0;
}

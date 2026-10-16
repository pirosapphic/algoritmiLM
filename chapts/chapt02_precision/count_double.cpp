#include<iostream>
#include<iomanip>
#include<cmath>
int main(){
    int N = 567002;
    double xend = M_PI;
    double dx = xend/N;
    double x;
    for(x=0; x < xend; x+=dx){
        x+=dx;
    }
    std::cout<<"finished, x="<<std::setprecision(9)<<x<<std::endl;
}

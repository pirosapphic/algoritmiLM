#include<fstream>
#include<iomanip>
#include<iostream>
#include<cmath>
#include"../../lib/derivators.h"


double f(double x);

int main(){
    double h = 0.5;
    double x = 1.;
    std::ofstream data;
    double reald = cos(x);
    data.open("derivative.dat");
    data << "#derivative errors data"<<std::endl<<
        "# 1/h    forward     backward    central     fourth"<<std::endl;
    for(int i = 0; i < 10; i++){
        double fd = forwardDiff(f,x,h);
        fd = fabs(fd-reald);
        double bd = backwardDiff(f,x,h);
        bd = fabs(bd-reald);
        double cd = centralDiff(f,x,h);
        cd = fabs(cd-reald);
        double hd = fourthOrderDiff(f,x,h);
        hd = fabs(hd-reald);

        data<<1./h<<" "<<fd<<" "<<bd<<" "<<cd<<" "<<hd<<std::endl;
        h/=2;
    }
    return 0;
}

double f(double x){
    return sin(x);
}

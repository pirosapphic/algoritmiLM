#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cmath>
#include<fstream>

//hit or miss method to compute PI
int main(){
    srand48(time(NULL));
    int N = 0;
    std::cout << "Number of points: ";
    std::cin >> N;
    //data.open("pi.dat");
    //data << "#hit or miss method for pi"<<std::endl<<"#x    y"<<std::endl;
    int hit = 0;
    for(int i = 0; i < N; i++){
        double x = 2.*(drand48()-0.5); //[-1,1]
        double y = 2.*(drand48()-0.5); //[-1,1]
        if( sqrt(x*x + y*y) <= 1. ) hit++;
        //data << x << "  "<< y << std::endl;
    }
    std::cout << "Estimate of pi = "
        <<(double) 2.*2.*hit/N<<std::endl; //Area*Nhits/Ntot
    std::cout << "Value of pi = "<<M_PI<<std::endl;
    //data.close();
    //we now search for the value of N which yields a relative error < tol
    std::ofstream data1; //for error data
    std::ofstream data2; //for the hit-miss plot
    double tol = 1.e-4;
    data1.open("pi_err.dat");
    data1 << "#Estimates of pi with hit or miss: errors"<<std::endl;
    data1 << "#N     err     pi_calc"<<std::endl;
    data2.open("pi.dat");
    data2 << "#Hit or miss data for pi estimation"<<std::endl;
    data2 << "#x     y"<<std::endl;
    N = 1;
    double err=0.;
    hit = 0;
    //this is better than increasing N and re-looping from the start: you can
    //continue to add points until the approximation is satisfactory.
    do{    
        N++;
        double x = 2.*(drand48()-0.5); //[-1,1]
        double y = 2.*(drand48()-0.5); //[-1,1]
        if( sqrt(x*x + y*y) <= 1. ) hit++;
        double pi_est = (double)2.*2.*hit/N;
        err = fabs(pi_est/M_PI-1); //or with std_dev, see slides
        data1 << N << "  " << err<< "  " <<pi_est << std::endl;
        data2 << x <<"  " << y << std::endl;
    } while(err > tol);
    std::cout<<"N = "<<N<<std::endl;
    data1.close();
    data2.close();
    return 0;
}

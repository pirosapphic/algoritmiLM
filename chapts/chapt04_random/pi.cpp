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
    std::ofstream data;
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
    double tol = 1.e-4;
    data.open("pi.dat");
    data << "#Estimates of pi with hit or miss"<<std::endl;
    data << "#N     err     pi_calc"<<std::endl;
    N = 1;
    double err=0.;
    do{    
        N+=1;
        hit = 0;
        for(int i = 0; i < N; i++){
            double x = 2.*(drand48()-0.5); //[-1,1]
            double y = 2.*(drand48()-0.5); //[-1,1]
            if( sqrt(x*x + y*y) <= 1. ) hit++;
        }
        double pi_est = (double)2.*2.*hit/N;
        err = fabs(pi_est/M_PI-1); //or with std_dev, see slides
        data << N << "  "<<"  "<< err<< "  " <<pi_est << std::endl;
    } while(err > tol);
    std::cout<<"N = "<<N<<std::endl;
    data.close();
    return 0;
}

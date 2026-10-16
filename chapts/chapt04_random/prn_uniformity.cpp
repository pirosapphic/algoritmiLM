#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

int main(){
    std::ofstream fdata;
    srand48(time(NULL));
    fdata.open("uniformity.dat");
    fdata << "#randomly generated data"<<std::endl;
    std::cout << "Generating random numbers in [0,1]..."<<std::endl;
    for(int i = 0; i < 1000; i++){
        double x = drand48();
        fdata << i <<"  "<<x<<std::endl;
    }
    fdata.close();
    std::cout<<"Done! See results in uniformity.dat"<<std::endl<<std::endl;
    std::cout<<"Evaluating the statistical moments of the distribution, while"
        <<" varying N"<<std::endl;
    fdata.open("./moments.dat");
    fdata<<"# <x> and <x^2> of uniform distribution (N, <x>, <x^2>)"<<std::endl;
    long unsigned int N;
    for(N = 2 ; N < 1e9; N*=2){
        double sumN1=0.0;
        double sumN2=0.0;
        for(long unsigned int i = 0; i<N; i++){
            double x = drand48();
            sumN1+=x;
            sumN2+=x*x;
        }
        sumN1 = (double)sumN1/N;
        sumN2 = (double)sumN2/N;
        fdata<<N<<"  "<<sumN1 - 1./(1.+1.)<<"  "<<sumN2-1./(2.+1.)<<std::endl;
    }
    fdata.close();
    std::cout<<"Done! Max N is "<<N/2.<<". See results in moments.dat"<<std::endl;
    return 0;
}

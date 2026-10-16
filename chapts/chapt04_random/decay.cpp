#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdlib.h>
#include<fstream>

int main(){
    srand48(time(NULL)); 
    std::ofstream data;
    double lam = 0.01;
    double dt = 1.;
    double tmax = 1000;
    int Nsteps = (int) tmax/dt;
    int N_0 = 1000;
    int Natoms = N_0;
    // we need to simulate a nuclear decay, after a step dt, the atoms that decay
    // are dN=lam*dt
    data.open("decay.dat");
    data << "#decay data with lambda = "<<lam<<std::endl;
    data << "#time  percentage  Natoms"<<std::endl;
    data <<0 <<"  "<< 1.<< "  "<< Natoms <<std::endl; 
    for(int i = 1; i <= Nsteps; i++){
        int decayed = 0;
        for(int j = 0; j < Natoms; j++){
            double prob = drand48();
            if( prob < lam ) decayed++;
        }
        Natoms -= decayed;
        data << (double) i*dt << "  " << (double) Natoms/N_0 << "  " << Natoms
             << std::endl;
        if( Natoms == 0 ) break;
    }
    return 0;
}

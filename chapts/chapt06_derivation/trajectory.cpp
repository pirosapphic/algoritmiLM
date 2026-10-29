#include<iostream>
#include<iomanip>
#include<fstream>
#include"../../lib/derivators.h"

double g_alpha;
double x_function(double t); //equation of motion

int main(){
    g_alpha = 30.;
    double t_f = g_alpha;
    double t_0 = 0.;
    const int Npoints = 10000;
    double dt = (double) (t_f-t_0)/Npoints;
    double x[Npoints+1];
    double v[Npoints+1];
    double a[Npoints+1];
    std::ofstream data;
    data.open("./trajectory.dat");
    data << "#data for the equation of function in trajectory.cpp"<<std::endl;
    data << "#t     x       v       a"<<std::endl;
    for(int i = 0; i < Npoints+1; i++){
        if( i==0 ){//problematic function in x=0, so the left 
            x[i]=x_function(i*dt);
            v[i]=forwardDiff(x_function, i*dt, dt);     
            a[i]=forwardSecondDer(x_function,i*dt,dt);
        }
        else if( i == Npoints+1 ){//for principle, since x(t) might not be defined
                                  //outside of [t_0,t_f]
            x[i]=x_function(i*dt);
            v[i]=backwardDiff(x_function,i*dt,dt);
            a[i]=backwardSecondDer(x_function, i*dt, dt);
        }
        else{
            x[i] = x_function(i*dt);
            v[i] = centralDiff(x_function, i*dt, dt);
            a[i] = centralSecondDer(x_function, i*dt, dt);
        }
        data << i*dt <<"  "<< x[i]<<"  "<<v[i]<<"  "<<a[i]<<std::endl;
        //std::cout << "t="<<i*dt<<" x="<<x[i]<<" v="<<v[i]<<" a="<<a[i]<<std::endl;
    }
    return 0;
}

double x_function(double t){
    if (t == 0 ) return 0; //right limit, since t_0>0
        return (double)g_alpha*t*t - t*t*t*(1.-exp(-g_alpha*g_alpha/t));
}

#include<iostream>
#include<cmath>

void solver1(double,double,double,double&,double&);
void solver2(double,double,double,double&,double&);

int main(){
    double a,b,c;
    std::cout<<"Quadratic equation solver"<<std::endl;
    std::cout<<"ax^2+bx+c=0"<<std::endl;
    std::cout<<"a = ";
    std::cin>>a;
    std::cout<<"b = ";
    std::cin>>b;
    std::cout<<"c = ";
    std::cin>>c;
    double x1,x2;
    solver1(a,b,c,x1,x2);
    std::cout<<"Solutions from solver 1 are (x1,x2) = ("<<x1<<", "<<x2<<")"
        <<std::endl;
    solver2(a,b,c,x1,x2);
    std::cout<<"Solutions from solver 2 are (x1,x2) = ("<<x1<<", "<<x2<<")"
        <<std::endl;
}

void solver1(double a,double b,double c,double& x1,double& x2){
    double Delta = b*b-4*a*c;
    x1 = (-b+sqrt(Delta))/(2*a);
    x2 = (-b-sqrt(Delta))/(2*a);
}

void solver2(double a,double b,double c,double& x1,double& x2){
    double Delta = b*b-4*a*c;
    if(b>=0){
        x2 = (-b-sqrt(Delta))/(2*a);
        x1 = 2*c/(-b-sqrt(Delta));
    }
    else if(b<0){
        x2 = 2*c/(-b+sqrt(Delta));
        x1 = (-b+sqrt(Delta))/(2*a);
    }
}   

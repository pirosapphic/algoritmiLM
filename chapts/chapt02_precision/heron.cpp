#include<iostream>
#include<iomanip>
#include<cmath>
//Heron's algorithm to find sqrt(S):
//one must find the solutions of x^2-S=0 recursively
//using a overestimating guess
//x_(n+1) = 0.5*(x_n+S/x_n)
int main(){
    double S;
    double x0;
    int n  = 6;//iterations
    std::cout<<"Enter the number S = ";
    std::cin>>S;
    std::cout<<"Guess of the sqrt = ";
    std::cin>>x0;
    double true_x = sqrt(S);
    double old_x=x0;
    double new_x;
    for(int i = 0; i < n; i++){
        std::cout<<"Iteration n."<<i<<": ";
        std::cout<<"x = "<<old_x;
        new_x = 0.5*(old_x + S/old_x);
        double err = fabs(old_x-new_x);
        std::cout<<"\tError: "<<err<<std::endl;
        old_x = new_x;
    }
}

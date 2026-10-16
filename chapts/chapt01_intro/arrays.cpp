#include<iostream>
#include <stdlib.h>
#include<cmath>

double mean(double*,int);
double variance(double*,int);
double variance(double*,int,double);

int main(){
    srand48(time(NULL));
    int n = 60000000;
    double* X = new double[n];
    for(int i = 0; i<n; i++){
        X[i]=pow(-1,i)*drand48();
    }
    double m = mean(X,n);
    double var = variance(X,n,m);
    std::cout<<"Mean is "<<m<<std::endl;
    std::cout<<"Variance is "<<var<<std::endl;
    double std_dev = pow(var,0.5);
    //now we identify which percentage of the data is out of 3sigma!
    int count = 0;
    double max = m+3*std_dev;
    double min = m-3*std_dev;
    std::cout<<"Std dev\t\tMin\t\tMax"<<std::endl;
    std::cout<<std_dev<<"\t"<<min<<"\t"<<max<<std::endl;
    for(int i = 0; i < n; i++){
        if(X[i]>max || X[i]<min) count+=1;
    }
    std::cout<<"The number of points out of 3 std deviations is "<<count;
    std::cout<<", which is "<<(double)count/n*100<<"% of the data."<<std::endl;
    delete X;
    X=nullptr;
    return 0;
}

double mean(double* arr, int n){
    double sum=0;
    for(int i = 0; i<n; i++){
        sum+=arr[i];
    }
    return sum/n;
};

double variance(double* arr,int n,double m){
    double sum = 0;
    //double m = mean(arr, n);
    for(int i = 0; i<n; i++){
        sum+=(m-arr[i])*(m-arr[i]);
    }
    return sum/n;
}
double variance(double* arr,int n){
    double m = mean(arr,n);
    return variance(arr,n,m);
}

#include<iostream>
#include<stdlib.h>
#include<cmath>

double mean(double*,int);
double variance(double*,int,double);
void simulate_uniform(int,double&);

int main(){
    srand48(time(NULL)); //initializing seed for drand48
    int N = 400000; //number of simulations
    int n = 1000; //dimension of each simulation
    double* means = new double[N];
    for(int j = 0; j < N; j++){
        simulate_uniform(n, means[j]);
        //std::cout<<"iteration "<<j<<": mean = "<<means[j]<<std::endl;
    }
    double m_means = mean(means,N);
    double var_means = variance(means, N, m_means);
    std::cout<<"Mean of means is "<<m_means<<std::endl;
    std::cout<<"std_dev of means is "<<sqrt(var_means)<<std::endl;
    double max = m_means + 3*sqrt(var_means);
    double min = m_means - 3*sqrt(var_means);
    int count = 0;
    for(int j = 0; j < N; j++){
        if(means[j]>max || means[j]<min){
            count +=1;
        }
    }
    std::cout<<"Only "<<count<<" means out of "<<N<<" are out of the 3sigma, which is "
        <<(double)count/N*100.<<"% of the total."<<std::endl;
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
    if(n>30) return sum/n;
    else return sum/(n-1);
}

void simulate_uniform(int n, double& m){
    double* X = new double[n];
    for(int i = 0; i < n; i++){
        X[i]=10*drand48();
    }
    m = mean(X,n);
    delete X;       //deleting these two lines makes your RAM explode!
    X = nullptr;    //because in the heap there will be n*N*sizeof(double)
    return;         //in this case this is 16e8 B = 1.6GB
}

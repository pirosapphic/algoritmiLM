#include<iostream>

int main(){
    int n,m;
    std::cout<< "First integer n = ";
    std::cin>>n;
    do{
	std::cout<< "Second integer m = ";
	std::cin>>m;
    }while(m==0);
    std::cout<<"sum\tdifference\tproduct\t\tinteger division\treal division"  
	<<std::endl;
    std::cout<<n+m;
    std::cout<<"\t";
    std::cout<<n-m;
    std::cout<<"\t\t";
    std::cout<<n*m;
    std::cout<<"\t\t";
    std::cout<<n/m;
    std::cout<<"\t\t\t";
    std::cout<<(double)n/m;
    std::cout<<std::endl;
    return 0;
}

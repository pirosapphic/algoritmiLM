#include<iostream>
#include<cmath>

double rectangle_rule(double (*func)(double), double a, double b, int N){
    double h = (b-a)/N; //this is the width of the rectangle
    double sum = 0;
    for(int i = 0; i < N; i++){
        double x_i = a+i*h;
        sum += func(x_i);
    }
    return sum*h;
}

double trapezoid_rule(double (*func)(double), double a, double b, int N){
    double h = (b-a)/N; //this is the width of the rectangle
    double sum = (func(a)+func(b))*0.5;
    for(int i = 1; i < N; i++){
        double x_i = a+i*h;
        sum += func(x_i);
    }
    return sum*h;
}

double simpson_rule(double (*func)(double),double a, double b, int N){
    double h = (b-a)/N; //this is the width of the rectangle
    double sum = func(a)+func(b);
    double w = 4.0;
    for(int i = 1; i < N; i++){
        //weight is 4/3 for odd i, 2/3 for even i
        w = 2.0 + 2.0*(i%2);
        double x_i = a+i*h;
        sum += w*func(x_i);
    }
    return sum*h/3.0;
}

double GaussianIntegrator(double (*func)(double),double a, double b, int N, int Ng){
    double xi[5];
    double wi[5];
    if(Ng == 2){
        xi[0] = -sqrt(1./3.); xi[1]=sqrt(1./3.);
        wi[0] = 1.;           wi[1]=1.;
    }
    else if(Ng == 3){
        xi[0] = -sqrt(0.6);xi[1]=0.;     xi[2]=sqrt(0.6);
        wi[0] = 5./9.;     wi[1]=8./9.;  wi[2]=5./9.;
    }
    else if(Ng == 4){
        xi[0]=sqrt(3./7. - 2./7.*sqrt(6./5.));
        xi[1]=-sqrt(3./7. - 2./7.*sqrt(6./5.));
        xi[2]=sqrt(3./7. + 2./7.*sqrt(6./5.));
        xi[3]=-sqrt(3./7. + 2./7.*sqrt(6./5.));

        wi[0]=(18.+sqrt(30.))/36.;
        wi[1]=(18.+sqrt(30.))/36.;
        wi[2]=(18.-sqrt(30.))/36.;
        wi[3]=(18.-sqrt(30.))/36.;
    }
    
    else if(Ng == 5){
        xi[0]=0.;
        xi[1]=1./3.*sqrt(5.-2.*sqrt(10./7.));
        xi[2]=-1./3.*sqrt(5.-2.*sqrt(10./7.));
        xi[3]=1./3.*sqrt(5.+2.*sqrt(10./7.));
        xi[4]=-1./3.*sqrt(5.+2.*sqrt(10./7.));

        wi[0]=128./225.;
        wi[1]=(322.+13.*sqrt(70.))/900.;
        wi[2]=(322.+13.*sqrt(70.))/900.;
        wi[3]=(322.-13.*sqrt(70.))/900.;
        wi[4]=(322.-13.*sqrt(70.))/900.;
    }
    //This is where the fun begins
    double h,sum,sumk,x0,x1;
    h = (double)(a+b)/N;
    sum = 0.;
    for(int i = 0; i < N; i++){
        //loop for the i-th interval: this starts at a+ih and ends at a+2ih.
        x0 = a+i*h;
        x1 = a+2*i*h;
        sumk = 0.;
        for(int k = 0; k < Ng; k++){
            //here we use gaussian quadrature on [x0,x1]
            sumk += wi[k]*func((x1-x0)*0.5*xi[k]+(x1+x0)*0.5);
        }
        sum += 0.5*(x1-x0)*sumk;
    }
    return sum;
}

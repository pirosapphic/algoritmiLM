#include "integrators.h"
double rectangleIntegrator(double (*func)(double), double a, double b, int N){
    double h = (b-a)/N; //this is the width of the rectangle
    double sum = 0;
    for(int i = 0; i < N; i++){
        double x_i = a+i*h;
        sum += func(x_i);
    }
    return sum*h;
}

double trapezoidIntegrator(double (*func)(double), double a, double b, int N){
    double h = (b-a)/N; //this is the width of the rectangle
    double sum = (func(a)+func(b))*0.5;
    for(int i = 1; i < N; i++){
        double x_i = a+i*h;
        sum += func(x_i);
    }
    return sum*h;
}

double simpsonIntegrator(double (*func)(double),double a, double b, int N){
    double h = (double)(b-a)/N; //this is the width of the rectangle
    double sum = func(a)+func(b);
    double w = 4.0;
    for(int i = 1; i < N; i++){
        double x_i = a+i*h;
        sum += w*func(x_i);
        //weight is 4/3 for odd i, 2/3 for even i
        w = 6.0 - w;
    }
    return sum*h/3.0;
}

double gaussianIntegrator(double (*func)(double),double a, double b, int N, int Ng){
    double xi[5];
    double wi[5];
    //we first define the zeros of the Legendre polynomials and their weights
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
    //We subdivide the integration interval in N intervals
    double sum,sumk,xc,dx;
    dx = (double)(b-a)/N;       //length of the interval
    sum = 0.;
    for(int i = 0; i < N; i++){ //loop over the intervals
        xc = a+ (i + 0.5)*dx;   //centre of the interval
        sumk = 0.;              //initialising the sum for each interval
        for(int k = 0; k < Ng; k++){
            sumk += wi[k]*func(0.5*dx*xi[k]+xc); //gaussian integration, with
        }                                        //the variable
                                                 //transformation
        sum += 0.5*dx*sumk;                      //[a,b]->[-1,1]
    }
    return sum;
}

double gaussianIntegrator2D(double (*func)(double,double),double ax,double bx,
        double ay, double by, int N, int Ng){
    //integrates a 2D function func over the region [ax,bx]x[ay,by], using N
    //subintervals for x,y and over each subinterval integrates with Ng gaussian
    //points.
    //we first define the zeros of the Legendre polynomials and their weights
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
    double dx = (double)(bx-ax)/N;
    double dy = (double)(by-ay)/N;
    double sum = 0.0;
    for(int iy = 0; iy < N; iy++){
        for(int ix = 0; ix < N; ix++){
            double xc = ax + (ix + 0.5)*dx;
            double yc = ay + (iy + 0.5)*dy;
            double sumy=0.0;
            for(int jy = 0; jy < Ng; jy++){
                double sumx = 0.0;
                for(int jx = 0; jx < Ng; jx++){
                    sumx += wi[jx]*func(xc+0.5*dx*xi[jx], yc+0.5*dy*xi[jy]);
                }
                sumx = sumx *0.5*dx;    //coefficient for the differential
                sumy = sumy + wi[jy]*sumx;
            }
            sumy = sumy*0.5*dy;         //coefficient for the differential
            sum+=sumy;
        }
    }
    return sum;
}




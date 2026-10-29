#include"root_finders.h"

//#define DEBUG //enables printing of iterations info

int bisectionRoot(double (*func)(double), double a, double b, double xtol,
        double ytol, double& zero){
    //Finds the root of func in the interval a,b using the bisection method with
    //tolerances xtol,ytol and puts it in zero and return the exit code.
    const int max_iterations=256;
    double ya = func(a);    double yb = func(b);
    if( ya*yb > 0){
        std::cout << "bisectionRoot() error: Interval may not contain zeroes!"
            <<" Exiting 1."<<std::endl;
        return 1;
    }
    int counter = 0;
    double xm,ym;
    do{
        counter++;
        if( counter > max_iterations){
            std::cout << "bisectionRoot() error: Max iterations ("
                <<max_iterations<<") exceeded! Exiting 2."<<std::endl;
            return 2;
        }
        if ( ya==0 ){
            zero = a;
            return 0;
        }
        if ( yb==0 ){
            zero = b;
            return 0;
        }
        xm = (b+a)*0.5;
        ym = func(xm);
        if (ya*ym < 0){
            b=xm;
            yb=ym;
        }
        else{
            a=xm;
            ya=ym;
        }
#ifdef DEBUG
        std::cout << "N = "<<counter<<"; [a,b]=["<<a<<","<<b<<"]; dx="<<fabs(b-a)
        <<"; "<<"xm="<<xm<<"; ym="<< ym<<std::endl;
#endif
    }while( (fabs(a-b) > xtol) && ( fabs(ym) > ytol) );
    zero = xm;
    return 0;
}

int regulaFalsi(double (*func)(double), double a, double b, double xtol,
        double ytol, double& zero){
    //Finds the root of func in the interval a,b using the regula falsi method
    //with tolerance tol and puts it in zero and return the exit code.
    const int max_iterations=256;
    double ya = func(a);    double yb = func(b);
    if( ya*yb > 0){
        std::cout << "regulaFalsi() error: Interval may not contain zeroes!"
            <<" Exiting 1."<<std::endl;
        return 1;
    }
    int counter = 0;
    double xm, ym;
    double diff = b-a;
    //double xm_new = (double)(b*yb-a*ya)/(b-a); //result of first try
    for(counter = 0; counter < max_iterations; counter++){
        if( ya == 0 ){  //pathological
            zero = a;
            return 0;
        }
        if( yb == 0 ){  //pathological
            zero = b;
            return 0;
        }
        xm = (double)(a*yb-b*ya)/(yb-ya); //uses the last try's final result
        ym = func(xm);
        //we change the extrema
        if (ya*ym < 0){
            diff = b-xm;
            b=xm;
            yb=ym;
        }
        else{
            diff = xm-a;
            a=xm;
            ya=ym;
        }
#ifdef DEBUG
        std::cout << "N = "<<counter<<"; [a,b]=["<<a<<","<<b<<"]; dx="<<fabs(b-a)
        <<"; "<<"xm="<<xm<<"; diff="<<diff<<std::endl;
#endif
        if( fabs(diff) < xtol || fabs(ym) < ytol || ym == 0.){
            zero = xm;
            return 0;
        }
    }
    std::cout << "regulaFalsi() error: Max iterations ("<< max_iterations
        <<") exceeded! Exiting 2"<<std::endl;
    return 2;
}

int secantRoot(double (*func)(double), double a, double b, double xtol,
        double ytol, double& zero){
    double ya,yb,xm,ym,deltax;
    ya = func(a);   yb = func(b);
    deltax = b - a;
    const int max_iterations = 128;
    double old_deltax = 1e6;    //absurdly big value
    for(int i = 0; i < max_iterations; i++){
        deltax = yb*(b-a)/(yb-ya);
        if ( (double)deltax/old_deltax > 10. ){
            std::cout << "secantRoot() warning: The interval is diverging!"
                <<std::endl;
        }
#ifdef DEBUG
        std::cout << "N = "<<i+1<<"; [a,b]=["<<a<<","<<b<<"]; dx="<<deltax
        <<std::endl;
#endif
        if( ya == 0){
            zero = a;
            return 0;
        }
        if( fabs(deltax) < xtol || fabs(yb) < ytol || yb == 0.){
            zero = b;
            return 0;
        }
        a = b;
        ya = yb;
        b = b-deltax;
        yb = func(b);
        old_deltax = deltax;
    }
    std::cout << "secantRoot(): Max iterations ("<<max_iterations<<") exceeded!"
        <<" Exiting 2."<<std::endl;
    return 2;
}

int newtonMethod(double (*func)(double), double (*d_func)(double), double a,
        double b, double xtol, double ytol, double& zero){
    //c=(a+b)/2 is the initial guess, d is the point found taking the tangent;
    double c = (double)0.5*(a+b);
    double fc, dfc, deltax;
    const int max_iterations = 128;
    double old_deltax = 1e6;    //absurdly big value
    for(int i = 0; i < max_iterations; i++){
        fc = func(c);
        dfc = d_func(c);
        deltax = (double)fc/dfc;
        c -= deltax;
#ifdef DEBUG
        if ( (double)deltax/old_deltax > 10. ){
            std::cout << "newtonMethod() warning: The interval is diverging!"
                <<std::endl;
        }
        std::cout << "N = "<<i+1<<"; xc ="<<c<<"; dx="<<deltax<<std::endl;
#endif
        if( fabs(deltax) < xtol || fabs(fc) < ytol || fc == 0){
            zero = c;
            return 0;
        }
        old_deltax = deltax;
    }
    std::cout << "newtonMethod(): Max iterations ("<<max_iterations<<") exceeded!"
        <<std::endl;
    return 2;
}


int multipleRoots(double (*func)(double), double a, double b, double N,
        int& Nroots, double* xL, double* xR){
    //takes the interval [a,b], divides it in N equal parts, stores
    //the left and right boundaries of subintervals with different signed extrema
    //in xL and xR and finally stores the number of found roots in Nroots; note
    //that xL and xR MUST be static arrays of size >Nroots, e.g. of size N.
    double dx = (double)(b-a)/N;
    double R,L;
    L = a;
    double fL,fR;
    fL = func(L);
    int root_count = 0;
    for(int i = 0; i < N; i++){
        R = L+dx;
        fR = func(R);
#ifdef DEBUG
        std::cout << i <<" ["<<L<<","<<R<<"]  f=["<<fL<<","<<fR<<"]"<<std::endl;
#endif
        if( fR*fL < 0 ){
            root_count++;
#ifdef DEBUG
            std::cout << "Root found in ["<<L<<","<<R<<"]!"<<std::endl;
#endif
            xL[root_count-1] = L;
            xR[root_count-1] = R;
        }
        L = R;
        fL = fR;
    }
    Nroots = root_count;
    return 0;
}









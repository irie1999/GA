#include <iostream>
#include <cmath>

#include "GA.h"

double fdtd(double parameter_beta_1, double parameter_beta_2, 
            double parameter_h_prime_1, double parameter_h_prime_2){
    double v; /*score*/
    double beta[3], h_prime[3];
    for(int t = 0; t <= 2; t++){
        beta[t] = parameter_beta_2 * pow(2, t[t] - t[0]) + parameter_beta_1 * (t[t] - t[0]) + beta[0];
        h_prime[t] = parameter_h_prime_2 * pow(2, t[t] - t[0]) + parameter_h_prime_1 * (t[t] - t[0]) + h_prime[0];
        
        cal_fdtd(); /*betaとh'を代入して電界を返す*/



    }




    return v;
}
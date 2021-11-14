#include <random>

#include "GA.h"

double fitting(double parameter_beta_1, double parameter_beta_2, 
            double parameter_h_prime_1, double parameter_h_prime_2){
    double v; /*score*/
    double u_beta_1 = 4.0, u_beta_2 = 5.0;
    double u_h_prime_1 = 6.0, u_h_prime_2 = 7.0;
    //double beta[3], h_prime[3];

    // for(int t = 0; t <= 2; t++){
    //     beta[t] = parameter_beta_2 * pow(2, t[t] - t[0]) + parameter_beta_1 * (t[t] - t[0]) + beta[0];
    //     h_prime[t] = parameter_h_prime_2 * pow(2, t[t] - t[0]) + parameter_h_prime_1 * (t[t] - t[0]) + h_prime[0];
        
    //     cal_fitting(beta[t], h_prime[t]); /*betaとh'を代入して電界を返す*/
    // }

    v = std::exp( - std::pow((parameter_beta_1 - u_beta_1), 2) - std::pow((parameter_beta_2 - u_beta_2), 2)
            - std::pow((parameter_h_prime_1 - u_h_prime_1), 2) - std::pow((parameter_h_prime_2 - u_h_prime_2), 2));

    return v;
}

void compose_roulette(const int N, Agent *agent, double *roulette){/*ルーレット作成*/
    double sum = 0.0; 
    

    for(int i = 0; i < Number_of_Individual; i++){
        sum += agent[i].score;
    }

    //double *roulette = new double[num];
    roulette[0] = agent[0].score / sum;
    for(int i = 1; i < Number_of_Individual ; i++){
        roulette[i] = roulette[i-1] + agent[i].score / sum;
    }
}

void crossover(int head, Agent *p, Agent *c, int *s){ /*交叉*/
  std::mt19937 rnd(1); 

    for(int i = 0; i < N_bit_total; i++){
        if(rnd() / i32 < 0.5){  /*入れ替えなし*/  
            c[head].Gene[i] = p[s[0]].Gene[i];  
            c[head+1].Gene[i] = p[s[1]].Gene[i];
        }
        else{                   /*入れ替えあり*/
            c[head].Gene[i] = p[s[1]].Gene[i];
            c[head+1].Gene[i] = p[s[0]].Gene[i];
        }
    }
}

int bin2dec(const int N_bit_initial, const int N_bit_end, bool *binary){
    /*2進数→10進数変換*/
    int v { 0 };
    int base { 1 };

    for(int i = N_bit_end - 1; i >= N_bit_initial; i--){
        v += int(binary[i]) * base;
        base *= 2;
    }
    return v;
}
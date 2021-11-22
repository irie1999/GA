#include <random>

#include "GA.h"

double fitting(double parameter_beta_1, double parameter_beta_2, 
            double parameter_h_prime_1, double parameter_h_prime_2){
    double v; /*score*/
<<<<<<< HEAD
     double u_beta_1 = 11.0, u_beta_2 = 10.0;
     double u_h_prime_1 = 6.0, u_h_prime_2 = 9.0;
=======
     double u_beta_1 = 1.0, u_beta_2 = 1.0;
     double u_h_prime_1 = 1.0, u_h_prime_2 = 1.0;
    // double beta[3], h_prime[3];
    // beta[0] = 0.49366;
    // h_prime[0] = 77.69128;
>>>>>>> score_graph

    // for(int t = 0; t <= 2; t++){
    //     beta[t] = parameter_beta_2 * pow((t[t] - t[0]), 2) + parameter_beta_1 * (t[t] - t[0]) + beta[0];
    //     h_prime[t] = parameter_h_prime_2 * pow((t[t] - t[0]), 2) + parameter_h_prime_1 * (t[t] - t[0]) + h_prime[0];
        
    //     cal_fdtd(beta[t], h_prime[t]); /*betaとh'を代入して電界を返す*/
    // }
    
     v = std::exp( - std::pow((parameter_beta_1 - u_beta_1), 2) - std::pow((parameter_beta_2 - u_beta_2), 2)
             - std::pow((parameter_h_prime_1 - u_h_prime_1), 2) - std::pow((parameter_h_prime_2 - u_h_prime_2), 2));

    // for(int i = 0; i < Nr; i++){
    //     for(int m = 1; m < M; m++){
    //         v += 1/ (Nr * (M - 1)) * std::pow(std::abs( S[i][m] - s[i][m] ), 2)
    //              + p_beta * std::pow(std::abs( beta[m] - beta[0]), 2) 
    //              + p_h_prime * std::pow(std::abs( h_prime[m] - beta[0]), 2);

    //     }
    // }
    

    return v;
}

void compose_roulette(const int N, Agent *agent, double *roulette, double *score_average, int n_generation){/*ルーレット作成*/
    double sum = 0.0; 

    for(int i = 0; i < Number_of_Individual; i++){
        sum += agent[i].score;
        //std::cout << "agent[" << i << "].score= " << agent[i].score << std::endl;
    }    
    score_average[n_generation] = sum / Number_of_Individual;
    //std::cout << "sum_average= " << sum_1 << std::endl;
    //std::cout << std::endl;
    //std::cout << "sum= " << sum << std::endl;
    roulette[0] = agent[0].score / sum;
      //std::cout << "roulette[0]= " << roulette[0] << std::endl;
      for(int i = 1; i < Number_of_Individual ; i++){
        roulette[i] = roulette[i-1] + agent[i].score / sum;
        // std::cout << "roulette[" << 3 << "]= " << roulette[3] << std::endl;
    }
}

void crossover(int head, Agent *p, Agent *c, int *s){ /*交叉*/
  //std::mt19937 rnd(1); 
  std::random_device rnd;
  std::mt19937 mt(rnd());

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
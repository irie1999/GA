#include <iostream>
#include <cmath>
#include <random>

#include "GA.h"

int main(void){
    int a;
    std::mt19937 rnd(1);
    double max, max_beta_1, max_beta_2, max_h_prime_1, max_h_prime_2;  /*最終世代スコアの最大値を判断*/ 

    Agent agent[2][Number_of_Individual];

    /*初期ランダム遺伝子の作成*/
    for(int i = 0; i < Number_of_Individual; i++){
        for(int n = 0; n < N_bit_total; n++){
            agent[0][i].Gene[n] = rnd() % 2;
        }
    }
    

    for(int n_generation = 0; n_generation < Number_of_Generation; n_generation++){
        const int PARENT { n_generation % 2 };
        const int CHILD { (n_generation + 1) % 2};

        for(int i = 0; i < Number_of_Individual; i++){
            agent[PARENT][i].set_parameter(agent[PARENT][i].Gene);  /* 2進数から10進数に変換*/
            
            agent[PARENT][i].score
                    = fitting( agent[PARENT][i].parameter_beta_1, agent[PARENT][i].parameter_beta_2,
                            agent[PARENT][i].parameter_h_prime_1, agent[PARENT][i].parameter_h_prime_2); 
                    /*FDTDの計算,返値がスコア*/
        }
        //std::cout << " beta_1 = " << agent[PARENT][0].parameter_beta_1 << " beta_2 = " << agent[PARENT][0].parameter_beta_2 
                  //<< " h_prime_1 = " << agent[PARENT][0].parameter_h_prime_1 << " h_prime_2 = " << agent[PARENT][0].parameter_h_prime_2 <<  std::endl; 

        /*ルーレット作成*/
        double *roulette = new double[Number_of_Individual];
        compose_roulette(Number_of_Individual, agent[PARENT], roulette);

        /*選択と交叉*/
        for(int i = 0; i < Number_of_Individual; i+=2){
            int sict[2];
            for(int j = 0; j <2 ; j++){
                double rnd_num = rnd() / i32;
                int k = 0;
                while( roulette[k] < rnd_num){  /*親を2体選ぶルーレット*/
                    k++;
                }
                sict[j] = k;
            }
            crossover(i, agent[PARENT], agent[CHILD], sict); /*交叉*/
        }

        /*突然変異*/
        for(int i = 0; i < Number_of_Individual; i++){
            for (int j = 0; j < N_bit_total; j++){
                if(rnd() / i32 < MUTATION ){
                    agent[CHILD][i].Gene[j] ^= 1;  /*0と1を反転*/
                }
            }
        }
    }
    
    /*最終世代の最もスコアが高いものを判断*/
    const int PARENT { Number_of_Generation % 2 };
    //const int CHILD { (Number_of_Generation + 1) % 2};
    max = agent[PARENT][0].score;

    for(int i = 0; i < Number_of_Individual; i++){
            agent[PARENT][i].set_parameter(agent[PARENT][i].Gene);  /* 2進数から10進数に変換*/
            agent[PARENT][i].score
                    = fitting( agent[PARENT][i].parameter_beta_1, agent[PARENT][i].parameter_beta_2,
                            agent[PARENT][i].parameter_h_prime_1, agent[PARENT][i].parameter_h_prime_2); 
                    /*FDTDの計算,返値がスコア*/
            if( max <= agent[PARENT][i].score){
                max = agent[PARENT][i].score;
                max_beta_1 = agent[PARENT][i].parameter_beta_1;
                max_beta_2 = agent[PARENT][i].parameter_beta_2;
                max_h_prime_1 = agent[PARENT][i].parameter_h_prime_1;
                max_h_prime_2 = agent[PARENT][i].parameter_h_prime_2;
            }
    }

    std::cout << "beta_1= " << max_beta_1 << std::endl 
              << "beta_2= " << max_beta_2 << std::endl
              << "h_prime_1= " << max_h_prime_1 << std::endl 
              << "h_prime_2= " << max_h_prime_2 << std::endl;

    return 0;

}

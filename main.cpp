#include <iostream>
#include <cmath>
#include <random>

#include "GA.h"

int main(void){
    std::mt19937 rnd(1);
    constexpr double i32 { 4294967296.0 }; /* 2^32 */

    constexpr double MUTATION { 0.03 }; /* 突然変異の確率 */
    constexpr int Number_of_Individual { 20 };  /*n個体*/
    constexpr int Number_of_Generation { 20 };  /*n世代*/
    
    Agent agent[2][Number_of_Individual];

    /*初期ランダム遺伝子の作成*/
    for(int i = 0; i < Number_of_Individual; i++){
        for(int n = 0; n < N_bit_parameters; n++){
            agent[0][i].Gene[n] = (rnd()/i32 > 0.5);
        }
    }

    for(int n_generation = 0; n_generation < Number_of_Generation; n_generation++){
        const int PARENT { n_generation % 2 };
        const int CHILD { (n_generation + 1) % 2};

        for(int i = 0; i < Number_of_Individual; i++){
            agent[PARENT][i].set_paremeter();  /* バイナリからパラメタに変換*/
            agent[PARENT][i].score
                    = fdtd( agent[PARENT][i].parameter1, agent[PARENT][i].parameter2) 
                    /*FDTDの計算,返値がスコア*/
        }

        /*ルーレット作成*/
        double roulette[Number_of_Individual];
        compose_roulette(Number_of_Individual, agent[PARENT], roulette);

        /*選択と交叉*/
        for(int i = 0; i < Number_of_Individual; i+=2){
            int sict[2];
            for(int j = 0; j <2 ; j++){
                double rnd_num = rnd() / i32;
                int k = 0;
                while( roulette[k] < rnd_num){
                    k++;
                }
                sict[j] = k;
            }
            crossover(i, agent[PARENT], agent[CHILD], sict); /*交叉*/
        }

        /*突然変異*/
        for(int i = 0; i < Number_of_Individual; i++){
            for (int j = 0; j < N_bit_parameters; j++){
                if(rnd() / i32 < MUTATION ){
                    individual[CHILD][i].chrom()[j] = 
                    not individual[CHILD][i].chrom()[j];
                }
            }
        }
    }
}

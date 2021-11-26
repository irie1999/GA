#include <iostream>
#include <fstream>
#include <cmath>
#include <random>

#include "GA.h"
#include "agent.h"
#include "fdtd/memory_allocate.h"

int main(void){
    std::cout << "a" << std::endl;
    std::random_device rnd;
    std::mt19937 mt(rnd());
    //std::mt19937 rnd(1); 
    double **s = allocate_memory2d(3, 801, 0.0);
    double **S = allocate_memory2d(3, 801, 0.0);
    double **Ei_tm = allocate_memory2d(3, 801, 0.0);
    double max_parameter[4];  /*最終世代スコアの最大値を判断*/ 
    double MAX[Number_of_Generation + 1];   /*最大値を格納*/
    double score_average[Number_of_Generation + 1]; /*平均値を格納*/
    double roulette[Number_of_Individual];  /*ルーレット*/
    Agent agent[2][Number_of_Individual];   /*個体*/
 
    create_ind(agent[0]); /*初期ランダム遺伝子の作成*/
    
    for(int n_generation = 0; n_generation < Number_of_Generation - 1; n_generation++){
        const int PARENT { n_generation % 2 };
        const int CHILD { (n_generation + 1) % 2};
        /*スコアを計算*/
        cal_ind(agent[PARENT], s, S, Ei_tm);
        
        /*スコア順にソート*/
        sort_ind(agent[PARENT]);

        /*各世代の最大値を格納*/
        MAX[n_generation] = agent[PARENT][0].score;

        /*ルーレットと平均値作成*/
        compose_roulette(Number_of_Individual, agent[PARENT], roulette, score_average, n_generation);    
        
        /*選択と交叉*/
        selection_crossover(roulette, agent[PARENT], agent[CHILD]);
        
        /*突然変異*/
        mutate_ind(agent[CHILD]);
        
    }
    
    /*最終世代の最もスコアが高いものを判断*/
    const int PARENT { (Number_of_Generation - 1) % 2 };
   
    final_cal_ind(agent[PARENT], max_parameter, MAX, score_average, s, S, Ei_tm);

    std::ofstream ofs("../data/" "score_graph");
    for(int n_generation = 0; n_generation < Number_of_Generation; n_generation++){
        ofs << n_generation << " " << MAX[n_generation] << " " << score_average[n_generation] << std::endl;
    }

    std::cout << "beta_1= " << max_parameter[0] << " beta_2= " << max_parameter[1]  << " h_prime_1= " << max_parameter[2]  
              << " h_prime_2= " << max_parameter[3] << " max= " << MAX[Number_of_Generation - 1] << std::endl;

    return 0;

}

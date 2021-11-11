#include "GA.h"

void compose_roulette(const int N, Agent *agent, double *roulette){
    double sum = 0.0;
    for(int i = 0; i < N; i++){
        sum += agent[i].scores[i];
    }

    double *roulette = new double[num];
    roulette[0] = scores[0] / sum;
    for(int i = 1; i < num; i++){
        roulette[i] = roulette[i-1] + scores[i] / sum;
    }
}

void crossover(int head, Agent *p, Agent *c, int *s){
    for(int i = 0; i < Nbit_total; i++){
        if(rnd() / i32 < 0.5){
            c[head].chrom()[i] = p[s[0]].chrom()[i];
            c[head+1].chrom()[i] = p[s[1]].chrom()[i];
        }
        else{
            c[head].chrom()[i] = p[s[1]].chrom()[i];
            c[head+1].chrom()[i] = p[s[0]].chrom()[i];
        }
    }
}
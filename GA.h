#ifndef GA_H_
#define GA_H_

#include <iostream>
#include <cmath>

constexpr int N_bit_parameter_beta_1 { 4 };
constexpr int N_bit_parameter_beta_2 { 4 };
constexpr int N_bit_parameter_h_prime_1 { 4 };
constexpr int N_bit_parameter_h_prime_2 { 4 };
constexpr int N_bit_total { N_bit_parameter_beta_1 + N_bit_parameter_beta_2 + N_bit_parameter_h_prime_1 + N_bit_parameter_h_prime_2 };
constexpr int N_bit_parameters_beta { N_bit_parameter_beta_1 + N_bit_parameter_beta_2 };
constexpr int N_bit_parameters_h_prime { N_bit_parameter_h_prime_1 + N_bit_parameter_h_prime_2 };
// constexpr double t[0] { 6.1667 }; /*6:10*/
// constexpr double t[1] { 6.313 }; 
// constexpr double t[2] { 6.5 }; 

constexpr double i32 { 4294967296.0 }; /* 2^32 */
constexpr double MUTATION { 0.03 }; /* 突然変異の確率 */
constexpr int Number_of_Individual { 20 };  /*n個体*/  /* gene * ind=400*/
constexpr int Number_of_Generation { 20 };  /*n世代*/

//constexpr int Max_Generation { 120 };



int bin2dec(const int N_bit_initial, const int N_bit_end, bool *binary);
void compose_roulette(const int N, class Agent *agent, double *roulette, double *score_average, int n_generation);
void crossover(int head, class Agent *p, class Agent *c, int *s);
double fitting(double parameter_beta_1, double parameter_beta_2, double parameter_h_prime_1, double parameter_h_prime_2);

#endif




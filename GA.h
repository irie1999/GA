#include <iostream>
#include <cmath>


constexpr int N_bit_total { 12 };
constexpr int N_bit_parameter_beta_1 { 3 };
constexpr int N_bit_parameter_beta_2 { 3 };
constexpr int N_bit_parameter_h_prime_1 { 3 };
constexpr int N_bit_parameter_h_prime_2 { 3 };
constexpr int N_bit_parameters_beta { N_bit_parameter_beta_1 + N_bit_parameter_beta_2 };
constexpr int N_bit_parameters_h_prime { N_bit_parameter_h_prime_1 + N_bit_parameter_h_prime_2 };
// constexpr double t[0] { 6.1667 }; /*6:10*/
// constexpr double t[1] { 6.313 }; 
// constexpr double t[2] { 6.5 }; 

constexpr double i32 { 4294967296.0 }; /* 2^32 */
constexpr double MUTATION { 0.05 }; /* 突然変異の確率 */
constexpr int Number_of_Individual { 60 };  /*n個体*/
constexpr int Number_of_Generation { 60 };  /*n世代*/
//constexpr int Max_Generation { 120 };



int bin2dec(const int N_bit_initial, const int N_bit_end, bool *binary);

class Agent{ /*各個体のクラス*/
private:
  double parameter_beta_1_min { 1.0 };
  double parameter_beta_1_max { 10.0 };
  double parameter_beta_1_step { (parameter_beta_1_max - parameter_beta_1_min) / (pow(2,N_bit_parameter_beta_1) - 1)};
  double parameter_beta_2_min { 1.0 };
  double parameter_beta_2_max { 10.0 };
  double parameter_beta_2_step { (parameter_beta_2_max - parameter_beta_2_min) / (pow(2,N_bit_parameter_beta_2) - 1)};
  double parameter_h_prime_1_min { 1.0 };
  double parameter_h_prime_1_max { 10.0 };
  double parameter_h_prime_1_step { (parameter_h_prime_1_max - parameter_h_prime_1_min) / (pow(2,N_bit_parameter_h_prime_1) - 1)};
  double parameter_h_prime_2_min { 1.0 };
  double parameter_h_prime_2_max { 10.0 };
  double parameter_h_prime_2_step { (parameter_h_prime_2_max - parameter_h_prime_2_min) / (pow(2,N_bit_parameter_h_prime_2) - 1)};


 public:
  bool Gene[N_bit_total];
  double parameter_beta_1, parameter_beta_2, parameter_h_prime_1, parameter_h_prime_2;
  void set_parameter(bool *Gene);
  double score;
};

void compose_roulette(const int N, Agent *agent, double *roulette);
void crossover(int head, Agent *p, Agent *c, int *s);

double fitting(double parameter_beta_1, double parameter_beta_2, 
            double parameter_h_prime_1, double parameter_h_prime_2);




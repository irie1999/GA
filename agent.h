#ifndef AGENT_H_
#define AGENT_H_

#include "GA.h"



class Agent{ /*各個体のクラス*/
private:
  double parameter_beta_1_min { 0.0 };
  double parameter_beta_1_max { 1.0 };
  double parameter_beta_1_step { (parameter_beta_1_max - parameter_beta_1_min) / (pow(2,N_bit_parameter_beta_1) - 1)};
  double parameter_beta_2_min { 0.0 };
  double parameter_beta_2_max { 1.0 };
  double parameter_beta_2_step { (parameter_beta_2_max - parameter_beta_2_min) / (pow(2,N_bit_parameter_beta_2) - 1)};
  double parameter_h_prime_1_min { 0.0 };
  double parameter_h_prime_1_max { 1.0 };
  double parameter_h_prime_1_step { (parameter_h_prime_1_max - parameter_h_prime_1_min) / (pow(2,N_bit_parameter_h_prime_1) - 1)};
  double parameter_h_prime_2_min { 0.0 };
  double parameter_h_prime_2_max { 1.0 };
  double parameter_h_prime_2_step { (parameter_h_prime_2_max - parameter_h_prime_2_min) / (pow(2,N_bit_parameter_h_prime_2) - 1)};


 public:
  bool Gene[N_bit_total];
  double parameter_beta_1, parameter_beta_2, parameter_h_prime_1, parameter_h_prime_2;
  void set_parameter(bool *Gene);
  double score;
};

#endif
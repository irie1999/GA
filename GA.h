#include <cmath>

constexpr int N_bit_parameter1 { 5 };
constexpr int N_bit_parameter2 { 3 };
constexpr int N_bit_parameters { N_bit_parameter1 + N_bit_parameter2 };
constexpr double t[0] { 6.1667 }; /*6:10*/
constexpr double t[1] { 6.313 }; 
constexpr double t[2] { 6.5 }; 

class Agent{ /*各個体のクラス*/
private:
  constexpr double Parameter1_min { 3.0 };
  constexpr double Parameter1_max { 5.0 };
  constexpr double Parameter1_step { (Parameter1_max - Parameter1_min) / (pow(2,N_bit_parameter1) - 1)};
  constexpr double Parameter2_min { 10.0 };
  constexpr double Parameter2_max { 20.0 };
  constexpr double Parameter2_step { (Parameter2_max - Parameter2_min) / (pow(2,N_bit_parameter2) - 1)};

public:
  bool Gene[N_bit_parameters];
  double parameter1, parameter2;
  void set_parameter(void);
  double score;
};

void Agent::set_parameter(void){
    parameter1 = Parameter1_min + Parameter1_step + bin2dec(N_bit_parameter1, Gene);
    parameter2 = Parameter2_min + Parameter2_step + bin2dec(N_bit_parameter2, Gene + N_bit_parameter1);

}

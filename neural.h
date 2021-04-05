#ifndef NEURAL_H
#define NEURAL_H
#include <vector>
#include <iostream>
//template <typename T>

class neural
{
private:
    /* data */
    std::vector<double> inputs {1,2,3,2.5};
    std::vector<std::vector<double>> weights {{0.2,0.8,-0.5,1.0},
                                              {0.5,-0.91,0.26,-0.5},
                                              {-0.26,-0.27,0.17,0.87}};
    std::vector<double> biases {2,3,0.5};
    std::vector<double> output {0,0,0};
public:
    neural(/* args */);
    ~neural();
    void calculateOutput();
};

#endif
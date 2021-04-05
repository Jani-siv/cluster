#ifndef LAYER_H
#define LAYER_H
#include <vector>
#include "input.h"
#include <random>
#include <time.h>

class layer
{
private:
    /* data */
    std::vector<std::vector<double>> weight;
    std::vector<double> bias;
    //pointer to input data
    input** data;
public:
    layer(int weights, int neurons,input* inputdata);
    ~layer();
    double randomDouble();
};


#endif
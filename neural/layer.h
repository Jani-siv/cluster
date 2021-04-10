#ifndef LAYER_H
#define LAYER_H
#include <vector>
#include <random>
#include <chrono>
#include <iostream>

class layer
{
private:
    /* data */
    std::vector<std::vector<long double>> weight;
    std::vector<long double> bias;
    //pointer to input data
    
    
public:
    layer(int weights, int neurons);
    ~layer();
    long double randomDouble();
    void testCout();
    long double getWeights(int row, int columns);
    long double getBias(int i);
    int getSizeRows();
    int getSizeColumns(int i);
    

};
#endif
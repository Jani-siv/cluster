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
    std::vector<std::vector<double>> weight;
    std::vector<double> bias;
    //pointer to input data
    
    
public:
    layer(int weights, int neurons);
    ~layer();
    double randomDouble();
    void testCout();
    double getWeights(int row, int columns);
    double getBias(int i);
    int getSizeRows();
    int getSizeColumns(int i);
    

};
#endif
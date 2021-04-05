#include "neural.h"

neural::neural(/* args */)
{
}

neural::~neural()
{
}

void neural::calculateOutput()
{
    double temp;
    for(int i=0; i < this->weights.size(); i++)
    {
        for(int j = 0; j < weights[i].size(); j++)
        {
       // std::cout<<"["<<this->weights[i][j]<<"] ";
        this->output[i] = this->output[i] + this->inputs[j] * this->weights[i][j];
        }
        this->output[i] += this->biases[i];
      std::cout<<std::endl;
    }
    for (int i = 0; i < this->output.size(); i++)
    {
    std::cout<<"Answer is: "<<this->output[i]<<std::endl;
    }
}
#include "layer.h"

layer::layer(int weights, int neurons)
{

srand(time(0));
//initialize weights with random number and set bias to all 0
for (int i = 0; i < neurons; i++)
{
    this->bias.push_back(0);
}
for (int i=0; i< neurons; i++)
{
    std::vector<long double> temp;
    this->weight.push_back(temp);

    for (int k=0; k < weights; k++)
    {
        long double tempDouble = this->randomDouble();
        this->weight[i].push_back(tempDouble);
    }
}

std::cout<<"class layer done"<<std::endl;
}

layer::~layer()
{
}

long double layer::randomDouble()
{
    unsigned int seed = std::chrono::steady_clock::now().time_since_epoch().count();
   double lower_bound = -1;
   double upper_bound = 1;
   std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
   std::default_random_engine re(seed);
   long double a_random_double = unif(re);
   return a_random_double;
}

void layer::testCout()
{
    std::cout<<"random weights between (-1) - 1:"<<std::endl;
    for (int i=0; i< this->weight.size(); i++)
    {
    for (int k=0; k < this->weight[i].size(); k++)
    {
        std::cout<<"["<<this->weight[i][k]<<"] ";
    }
    std::cout<<std::endl;
    }
}
long double layer::getWeights(int row, int columns)
{
    return this->weight[row][columns];
}

long double layer::getBias(int i)
{
    return this->bias[i];
}

int layer::getSizeRows()
{
    //size on rows
    return weight.size();
}

int layer::getSizeColumns(int i)
{
return weight[i].size();
}

std::vector<long double> layer::getWeights(int position)
{
return this->weight[position];
}
int layer::getAmountWeights()
{
    return this->weight.size();
}
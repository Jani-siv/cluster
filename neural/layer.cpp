#include "layer.h"

layer::layer(int weights, int neurons, input* inputData)
{
this->data = &inputData;
srand(time(0));
//initialize weights with random number and set bias to all 0
for (int i = 0; i < neurons; i++)
{
    this->bias[i] = 0;
}
for (int i=0; i< neurons; i++)
{
    for (int k=0; k < weights; k++)
    {
        this->weight[i][k] = this->randomDouble();
    }
}
}

layer::~layer()
{
}

double layer::randomDouble()
{
   double lower_bound = -1;
   double upper_bound = 1;
   std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
   std::default_random_engine re;
   double a_random_double = unif(re);

   return a_random_double;
}
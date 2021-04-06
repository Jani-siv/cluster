#include "neural.h"

neural::neural(/* args */)
{
}

neural::~neural()
{
}

void neural::calculateOutput()
{
    auto start = std::chrono::high_resolution_clock::now();
    //set inputs
    this->setInput();
    //make first layer
    layer testi(4,3);
    for(int k = 0; k < this->inputClass.size(); k++)
    {
    // one for loop more for multiple inputs
    for(int i=0; i < this->weights.size(); i++)
    {
        for(int j = 0; j < weights[i].size(); j++)
        {
       // std::cout<<"["<<this->weights[i][j]<<"] ";
        this->output[i] = this->output[i] + this->inputClass[k]->getData(j) * testi.getWeights(i,j);//this->weights[i][j];
       // std::cout<<"testi:"<<testi.getWeights(i,j)<<std::endl;
        }
        this->output[i] += testi.getBias(i);
        std::cout<<"Output from "<<i<<" is:"<<this->getOutput(i)<<std::endl;
      std::cout<<std::endl;
    }
    for (int i = 0; i < this->output.size(); i++)
    {
    std::cout<<"Answer is: "<<this->output[i]<<std::endl;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<<duration.count()<<"microseconds"<<std::endl;
    }
    //remove this test
    
    testi.testCout();
}

//creating new class and push it in vector
//add values on class
void neural::setInput()
{
  input *classInput = new input;
  this->inputClass.push_back(classInput);
  this->inputClass[this->inputs]->setData(1);
  this->inputClass[this->inputs]->setData(2);
  this->inputClass[this->inputs]->setData(3);
  this->inputClass[this->inputs]->setData(2.5);
  this->inputs++;
}

double neural::getOutput(int i)
{
  return this->output[i];
}
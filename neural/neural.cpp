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
    double temp;
    this->setInput();
    for(int k = 0; k < this->inputClass.size(); k++)
    {
    // one for loop more for multiple inputs
    for(int i=0; i < this->weights.size(); i++)
    {
        for(int j = 0; j < weights[i].size(); j++)
        {
       // std::cout<<"["<<this->weights[i][j]<<"] ";
        this->output[i] = this->output[i] + this->inputClass[k]->getData(j) * this->weights[i][j];
        }
        this->output[i] += this->biases[i];
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
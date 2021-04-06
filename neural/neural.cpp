#include "neural.h"

neural::neural(/* args */)
{
}

neural::~neural()
{
}
//from file
void neural::calculateOutput()
{
    auto start = std::chrono::high_resolution_clock::now();

    for(int k = 0; k < this->inputClass.size(); k++)
    {
    // one for loop more for multiple inputs
    for(int i=0; i < this->layerClass[0].getSizeRows() ; i++)
    {
        for(int j = 0; j < this->layerClass[0].getSizeColumns(i); j++)
        {
       // std::cout<<"["<<this->weights[i][j]<<"] ";
        this->output[i] = this->output[i] + this->inputClass[k]->getData(j) * this->layerClass[this->layerPosition].getWeights(i,j);//testi.getWeights(i,j);
       // std::cout<<"testi:"<<testi.getWeights(i,j)<<std::endl;
        }
        this->output[i] += this->layerClass[this->layerPosition].getBias(i);
        std::cout<<"Output from "<<i<<" is:"<<this->getOutput(i)<<std::endl;
        //save layer output in vector for later use
        this->layerOutput.push_back(this->output);
    }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<<duration.count()<<"microseconds"<<std::endl;
    //get weights and print out
}

//creating new class and push it in vector
//add values on class
void neural::setInput()
{
  //make this read from file first inputs
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

void neural::runProgram()
{
    //set inputs
    this->setInput();
    //make first layer
    layer firstRound(this->inputClass[0]->getSize(),3);
    this->layerClass.push_back(firstRound);
    this->calculateOutput();
    std::cout<<"start setting output to input"<<std::endl;
    this->setOutputToInput();
     std::cout<<"making new object"<<std::endl;
    layer layer1(this->inputClass[0]->getSize(),2);
    this->layerClass.push_back(layer1);
     std::cout<<"start calculate layer output"<<std::endl;
    this->calculateLayerOutput();
    this->layerPosition++;
    
    // set output to input

}
//layer output to next layer input
void neural::setOutputToInput()
{
  input *classLayerInput = new input;
  std::cout<<"toimiiko"<<std::endl;
  std::vector<input*> temp;
  temp.push_back(classLayerInput);
  this->layerInput.push_back(temp);

  std::cout<<"tässä ollaaan"<<std::endl;
for (int i =0; i < this->layerOutput.size(); i++)
{
  std::cout<<"setting data"<<std::endl;
  this->layerInput[this->layerPosition][this->layerPosition]->setData(this->layerOutput[this->layerPosition][i]);
}
}

void neural::calculateLayerOutput()
{
    for(int k = 0; k < this->layerInput[this->layerPosition].size(); k++)
    {
    // one for loop more for multiple inputs
    for(int i=0; i < this->layerClass[this->layerPosition+1].getSizeRows(); i++)
    {
        for(int j = 0; j < this->layerClass[this->layerPosition+1].getSizeColumns(i); j++)
        {
       // std::cout<<"["<<this->weights[i][j]<<"] ";
        this->output[i] = this->output[i] + this->inputClass[k]->getData(j) * this->layerClass[this->layerPosition].getWeights(i,j);//testi.getWeights(i,j);
       // std::cout<<"testi:"<<testi.getWeights(i,j)<<std::endl;
        }
        this->output[i] += this->layerClass[this->layerPosition].getBias(i);
        std::cout<<"Output from "<<i<<" is:"<<this->getOutput(i)<<std::endl;
        //save layer output in vector for later use
        this->layerOutput.push_back(this->output);
    }
    }

}
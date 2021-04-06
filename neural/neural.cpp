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

    for(int k = 0; k < this->inputClass.size(); k++)
    {
    // one for loop more for multiple inputs
    for(int i=0; i < this->layerClass[this->layerPosition].getSizeRows() ; i++)
    {
        for(int j = 0; j < this->layerClass[this->layerPosition].getSizeColumns(i); j++)
        {
        this->output[i] = this->output[i] + this->inputClass[k]->getData(j) * this->layerClass[this->layerPosition].getWeights(i,j);
        }
        this->output[i] += this->layerClass[this->layerPosition].getBias(i);
        std::cout<<"Output from "<<i<<" is:"<<this->getOutput(i)<<std::endl;
        //save layer output in vector for later use
        //this need fix up other we need calculate how many neurons is in every layer
        this->layerOutput.push_back(this->output);
        
    }
    this->layerClass[this->layerPosition].testCout();
    }
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
    //set layer class to vector
    this->layerClass.push_back(firstRound);
    //calculate first round from input file
    this->calculateOutput();
    //set first round output to second layer input
    //this need old position of layer dont update yet
    this->setOutputToInput();
    //create new hidden layer inputClass[this->layerPosition]->getSize()
    layer layer1(this->layerOutput[this->layerPosition].size(),2); //modify input class to abstract
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
  std::vector<input*> temp;
  temp.push_back(classLayerInput);
  this->layerInput.push_back(temp);
for (int i =0; i < this->layerOutput[this->layerPosition].size(); i++)
{
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
        this->output[i] = this->output[i] + this->inputClass[k]->getData(j) * this->layerClass[this->layerPosition].getWeights(i,j);
        }
        this->output[i] += this->layerClass[this->layerPosition].getBias(i);
        std::cout<<"Output from "<<i<<" is:"<<this->getOutput(i)<<std::endl;
        //save layer output in vector for later use
        this->layerOutput.push_back(this->output);
    }
    }
  this->layerClass[this->layerPosition+1].testCout();
}
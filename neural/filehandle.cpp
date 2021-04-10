#include "filehandle.h"

filehandle::filehandle(/* args */)
{
}

filehandle::~filehandle()
{
}

int filehandle::openFile(std::string filename)
{
std::fstream currentFile;
currentFile.open(this->directory+filename,std::ios::in);
if (!currentFile)
{
    std::cout<<"error cannot open file"<<this->directory+filename<<std::endl;
    return -1;
}
else {
    std::cout<<"file opened for reading"<<std::endl;
    return 0;
    currentFile.close();
}
return -2;
//open file
}
void filehandle::saveCurrentToFile(std::vector<std::vector<double>> *layer)
{
//set all weights and biases in file

}
void filehandle::loadWeightsFromFile()
{
    //load saved
}
std::vector<double> filehandle::setAnswers(std::string filename)
{
    this->error = this->openFile(filename);
    //transform to read from file
    std::vector<double> answer;
    answer.push_back(1);
    answer.push_back(0);
    answer.push_back(0);
    return answer;
    //set answers for training
}
#include "filehandle.h"

filehandle::filehandle(/* args */)
{
}

filehandle::~filehandle()
{
    this->currentfile.close();
}

int filehandle::openFile(std::string filename)
{
this->currentfile.open(this->directory+filename,std::ios::in);
if (!this->currentfile)
{
    std::cout<<"error cannot open file"<<this->directory+filename<<std::endl;
    return -1;
}
else {
    std::cout<<"file opened for reading"<<std::endl;
    return 0;
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
void filehandle::setAnswers(std::string filename)
{
    //test file
    this->error = this->openFile(filename);
    if (this->error == 0)
    {
        std::string output;
        while (getline (this->currentfile, output))
        {
            std::vector<double> oneTraining;
            std::stringstream templine (output);
                while(getline (templine,output,','))
                {
                    double tempVariable = std::atof(output.c_str());        
                    oneTraining.push_back(tempVariable);
                }
        this->answers.push_back(oneTraining);
        }
    }
    
}
int filehandle::getAnswersSize()
{
    return this->answers.size();
}

std::vector<double> filehandle::getAnswers(int place)
{
    return this->answers[place];
}